#include "decoder.h"
#include <Magick++.h>
#include <string>
#include "histogramResult.h"
#include "alphaConverter.h"
#include <vector>
#include "numberSystem.h"
#include "fibonacciSystem.h"
#include <assert.h>
#include "encoder.h"
#include "chunker.h"
#include "compressor.h"
#include "code39.h"

using namespace std;
using namespace Magick;

// =================== Image Statistics ============================
histogramResult Decoder::VerticalHistogram(Image* image, size_t startingY){
    // Ensure that there are no other references to this image
    image->modifyImage();
    // Set the image type to TrueColor DirectClass representation.
    image->type(TrueColorType);

    //create histogram
    histogramResult hist;

    // Request pixel region with size nrows x ncolumns, and top origin at 0x0
    size_t nrows = moduleHeight;
    size_t ncolumns = image->columns();
    PixelPacket *pixel_cache = image->getPixels(0,startingY,ncolumns,nrows);
    if(pixel_cache == NULL){
        // problem decoding (i.e. decoding 1D barcode when it is actually 2D)
        hist.length = 0;
        return hist;
    }

    //initialize hist starting values
    hist.max = 0;
    hist.min = Color("white").blueQuantum() + Color("white").redQuantum() + Color("white").greenQuantum();
    hist.length = ncolumns;
    hist.histogram = new double[ncolumns];

    if(pixel_cache != NULL){
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
    }
    return hist;
}


string Decoder::ReadCode39(Image* image){
    // To find a horizontal barcode, find the vertical histogram to find individual barcodes,
    // then get the vertical histogram to decode each
    moduleHeight = ONE_D_HEIGHT;
    histogramResult vertHist = VerticalHistogram(image, 0);


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
                    patternString += "N";
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
                        patternString += "W";
                        nBarStart = i;
                    }
                    else
                    {
                        // The light bar is a narrow bar
                        patternString += "N";
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

    patternString += 'N';

    // We now have a barcode in terms of narrow & wide bars... Parse it!
    string dataString = "";

    // Each pattern within code 39 is nine bars with one white bar between each pattern
    dataString = Code39::decodeBarcode(patternString);

    return dataString;
}

// =================== Fibonacci ============================
/** Converts pixel pattern to bit pattern for a given row in image */
vector<int> Decoder::ImageToBits(histogramResult *vertHist){
    // Set the threshold for determining dark/light bars to half way between the histograms min/max
    double threshold = vertHist->min + ((vertHist->max - vertHist->min)/2);

    // Variables needed to check for
    vector<int> pattern;
    int nBarStart = -1;
    int nNarrowBarWidth = -1;
    int barWidthErrorThresh = -1;
    bool bDarkBar = false;

    // Find the narrow and wide bars
    for (size_t i = 0; i < vertHist->length; ++i)
    {
        // First find the narrow bar width
        if (nNarrowBarWidth < 0)
        {
            if (nBarStart < 0)
            {
                // The code doesn't start until we see a dark bar
                if (vertHist->histogram[i] <= threshold)
                {
                    // We detected a dark bar, save it's start position
                    nBarStart = i;
                }
            }
            else
            {
                if (vertHist->histogram[i] > threshold)
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
                if (vertHist->histogram[i] > threshold)
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
                if (vertHist->histogram[i] <= threshold)
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
    return pattern;
}

void Decoder::PatternToBinary(vector<int> *pattern, vector<int> *binary){
    int end = (int) pattern->size() - 1; // pattern includes ending white but not the ending black bar
    for(int i = 2; i < end; i++) binary->push_back(pattern->at(i)); //ignore starting black and white bars
}

string Decoder::VectorToString(vector<float> *data){
    float total = 0;
    for(size_t i = 0; i <data->size(); i++) total += data->at(i);
    stringstream result;
    result << total;
    return result.str();
}

void Decoder::SetDimensions(Image *image, BarcodeType type){
    if(type == OneDimensional){
        nrows = 1;
        moduleHeight = ONE_D_HEIGHT;
    } else {
        nrows = image->rows() / TWO_D_HEIGHT;
        moduleHeight = TWO_D_HEIGHT;
    }
}

string Decoder::ReadFusion(Image* image, NumberSystem *sys, BarcodeType type){
    SetDimensions(image, type); //set reading dimensions
    vector<int> binary; //binary from all rows
    for(size_t i = 0; i < nrows; i++){
        // To find a horizontal barcode, find the vertical histogram to find individual barcodes,
        // then get the vertical histogram to decode each
        histogramResult vertHist = VerticalHistogram(image, i*TWO_D_HEIGHT);
        if(vertHist.length == 0) return ERROR_STRING2;
        vector<int> pattern = ImageToBits(&vertHist);
        delete[] vertHist.histogram;
        PatternToBinary(&pattern, &binary);
    }
    vector<int> uncompressedBinary = Compressor::ExpandBitSequence(&binary, sys);
    Chunker chunker;
    return chunker.GetNumberRepresentation(uncompressedBinary, sys);
}

