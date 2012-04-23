//============================================================================
// Name        : barcodeDecoder.cpp
//============================================================================
#include <Magick++.h>
#include <iostream>
#include <string>
using namespace std;
using namespace Magick;

struct histogramResult {
	double *histogram;
	size_t length;
	double max;
	double min;
};

static histogramResult VerticalHistogram(Image image){
	// Ensure that there are no other references to this image.
	image.modifyImage();
	// Set the image type to TrueColor DirectClass representation.
	image.type(TrueColorType);
	// Request pixel region with size nrows x ncolumns, and top origin at 0x0
	size_t nrows = image.rows();
	size_t ncolumns = image.columns();

	//create histogram
	histogramResult hist;
	hist.histogram = new double[ncolumns];
	hist.length = ncolumns;
	hist.max = 0;
	hist.min = Color("white").blueQuantum() + Color("white").redQuantum() + Color("white").greenQuantum();

	PixelPacket *pixel_cache = image.getPixels(0,0,ncolumns,nrows);
	// Set each pixel in the cache to a fixed color.
	for(size_t col = 0; col < ncolumns; col++){
		double avgPixelValue = 0;
		for(size_t row = 0; row < nrows ; row++){
			PixelPacket *pixel = pixel_cache+row*ncolumns + col;
			//printf("%d %d %d\n",pixel->red, pixel->green, pixel->blue);
			avgPixelValue += (pixel->red + pixel->green + pixel->blue);
			*pixel = Color("blue");
		}
		avgPixelValue /= (nrows*3);
		hist.histogram[col] = avgPixelValue;
		if(avgPixelValue > hist.max){
			hist.max = avgPixelValue;
		} else if (avgPixelValue < hist.min){
			hist.min = avgPixelValue;
		}
		//printf("average for col %d is %f\n", col, avgPixelValue);
	}
	//printf("min is %f max is %f\n", hist.min, hist.max);
	// Save changes to underlying image .
	image.syncPixels();
	// Save updated image to file.
	//image.write("x4.gif");
	return hist;
}

static string parsePattern(string pattern){
	if(!pattern.compare("wnnwnnnnw")){
		return "1";
	} else if (!pattern.compare("nnwwnnnnw")){
		return "2";
	} else if (!pattern.compare("wnnnnwnnw")){
		return "A";
	} else if (!pattern.compare("nnnnwwnnw")){
		return "D";
	} else if (!pattern.compare("nnnnwnwwn")){
		return "T";
	} else {
		return "*";
	}
}

static string ReadCode39(Image image){
	// To find a horizontal barcode, find the vertical histogram to find individual barcodes,
	// then get the vertical histogram to decode each
	histogramResult vertHist = VerticalHistogram(image);


	// Set the threshold for determining dark/light bars to half way between the histograms min/max
	double threshold = vertHist.min + ((vertHist.max - vertHist.min)/2);

	// Variables needed to check for
	string patternString = "";
	int nBarStart = -1;
	int nNarrowBarWidth = -1;
	bool bDarkBar = false;



	// Find the narrow and wide bars
	for (size_t i = 0; i < vertHist.length; ++i)
	{
		// First find the narrow bar width
		if (nNarrowBarWidth < 0)
		{
			if (nBarStart < 0)
			{
				// The code doesn't start until we see a dark bar
				if (vertHist.histogram[i] <= threshold)
				{
					// We detected a dark bar, save it's start position
					nBarStart = i;
				}
			}
			else
			{
				if (vertHist.histogram[i] > threshold)
				{
					// We detected the end of first the dark bar, save the narrow bar width and
					// start the rest of the barcode
					nNarrowBarWidth = i - nBarStart + 1;
					patternString += "n";
					nBarStart = i;
					bDarkBar = false;
				}
			}
		}
		else
		{
			if (bDarkBar)
			{
				// We're on a dark bar, detect when the bar becomes light again
				if (vertHist.histogram[i] > threshold)
				{
					if ((i-nBarStart) > (nNarrowBarWidth))
					{
						// The light bar was wider than the narrow bar width, it's a wide bar
						patternString += "w";
						nBarStart = i;
					}
					else
					{
						// The light bar is a narrow bar
						patternString += "n";
						nBarStart = i;
					}
					bDarkBar = false;
				}
			}
			else
			{
				// We're on a light bar, detect when the bar becomes dark
				if (vertHist.histogram[i] <= threshold)
				{
					if ((i-nBarStart) > (nNarrowBarWidth))
					{
						// The dark bar was wider than the narrow bar width, it's a wide bar
						patternString += "w";
						nBarStart = i;
					}
					else
					{
						// The dark bar is a narrow bar
						patternString += "n";
						nBarStart = i;
					}
					bDarkBar = true;
				}
			}
		}
	}

	// We now have a barcode in terms of narrow & wide bars... Parse it!
	string dataString = "";

	// Each pattern within code 39 is nine bars with one white bar between each pattern
	for(size_t i=0; i<patternString.length()-1; i+=10)
	{
		string pattern = patternString.substr(i, 9);
		dataString += parsePattern(pattern);
	}

	return dataString;
}


int main(int argc,char **argv)
{
	// Construct the image object. Seperating image construction from the
	// the read operation ensures that a failure to read the image file
	// doesn't render the image object useless.
	Image image;
	try {
		// Read a file into image object
		image.read("sample_barcode.gif");
	}
	catch( Exception &error_ )
	{
		cout << "Caught exception: " << error_.what() << endl;
		return 1;
	}
	string data = ReadCode39(image);
	for(size_t i = 0; i < data.length(); i++){
		printf("%c", data[i]);
	}
	printf("\n");
	return 0;
}


