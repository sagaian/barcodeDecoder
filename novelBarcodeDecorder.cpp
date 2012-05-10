/*
 * novelBarcodeDecorder.cpp
 *
 *  Created on: Apr 11, 2012
 *      Author: sagaian
 */
/*#include <Magick++.h>
#include <iostream>
#include <string>
#include "numberSystem.h"
#include "fibonacciSystem.h"
#include <assert.h>
using namespace std;
using namespace Magick;

struct histogramResult {
	double *histogram;
	size_t length;
	double max;
	double min;
};

void PrintVector(vector<int> v){
	for(size_t i = 0; i < v.size();i++)
		cout<< v.at(i) << " ";
	cout << "\n";
}

void PrintVector(vector<float> v){
	for(size_t i = 0; i < v.size();i++)
		cout<< v.at(i) << " ";
	cout << "\n";
}

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
			avgPixelValue += (pixel->red + pixel->green + pixel->blue);
		}
		avgPixelValue /= (nrows*3);
		hist.histogram[col] = avgPixelValue;
		if(avgPixelValue > hist.max){
			hist.max = avgPixelValue;
		} else if (avgPixelValue < hist.min){
			hist.min = avgPixelValue;
		}
	}
	return hist;
}


static vector<int> ImageToBits(Image image){
	// To find a horizontal barcode, find the vertical histogram to find individual barcodes,
	// then get the vertical histogram to decode each
	histogramResult vertHist = VerticalHistogram(image);


	// Set the threshold for determining dark/light bars to half way between the histograms min/max
	double threshold = vertHist.min + ((vertHist.max - vertHist.min)/2);

	// Variables needed to check for
	vector<int> pattern;
	int nBarStart = -1;
	int nNarrowBarWidth = -1;
	int barWidthErrorThresh = -1;
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
					nNarrowBarWidth = i - nBarStart;
					barWidthErrorThresh = nNarrowBarWidth/2;
					pattern.push_back(1);
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
					int nPixels = i - nBarStart;
					while(nPixels >= nNarrowBarWidth)
					{
						pattern.push_back(1);
						nPixels -= nNarrowBarWidth;
					}
					//account for read error
					if(nPixels >= nNarrowBarWidth - barWidthErrorThresh ) {
						pattern.push_back(1);
					}
					nBarStart = i;
					bDarkBar = false;
				}
			}
			else
			{
				// We're on a light bar, detect when the bar becomes dark
				if (vertHist.histogram[i] <= threshold)
				{
					int nPixels = i - nBarStart;
					while(nPixels >= nNarrowBarWidth)
					{
						pattern.push_back(0);
						nPixels -= nNarrowBarWidth;
					}
					//account for read error
					if(nPixels >= nNarrowBarWidth - barWidthErrorThresh ) {
						pattern.push_back(0);
					}
					nBarStart = i;
					bDarkBar = true;
				}
			}
		}
	}
	delete[] vertHist.histogram;
	return pattern;
}

vector<float> BitsToData(vector<int> pattern, NumberSystem *sys){
	vector<float> *seq = sys->getSequence();
	PrintVector(*seq);
	int end = (int) pattern.size();
	assert(end == (int) seq->size());
	vector<float> data;
	for(int i = 0; i < end; i++){
		if(pattern.at(i)){
			data.push_back(seq->at(i));
		}
	}
	delete seq;
	return data;
}

int main(int argc,char **argv)
{
	// Construct the image object. Seperating image construction from the
	// the read operation ensures that a failure to read the image file
	// doesn't render the image object useless.
	Image image;
	try {
		// Read a file into image object
		image.read("sample_barcode_2.gif");
	}
	catch( Exception &error_ )
	{
		cout << "Caught exception: " << error_.what() << endl;
		return 1;
	}
	vector<int> pattern = ImageToBits(image);
	PrintVector(pattern);
	Fibonacci f(1,1,(int) pattern.size());
	vector<float> data = BitsToData(pattern, &f);
	PrintVector(data);
	return 0;
}*/
