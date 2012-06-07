/*
 * decoder.h
 */
#ifndef DECODER_H
#define DECODER_H

#include <Magick++.h>
#include <string>
#include "histogramResult.h"
#include <vector>
#include "numberSystem.h"
#include <sstream>
#include <encoder.h>

using namespace std;
using namespace Magick;

class Decoder {    
public:
    /** Barcode decoding currently supported */
    enum BarcodeType{
        OneDimensional,
        TwoDimensional
    };

    /** Decodes Code39 barcode and returns data string */
    string ReadCode39(Image* image);

    /** Decodes Fusion code based on type and number system and returns data string */
    string ReadFusion(Image* image, NumberSystem *sys, BarcodeType type);

private:
    /* private instance variables */
    size_t moduleHeight; //height (pixels) of one white/black bar
    size_t nrows; // number of rows with moduleHeight

    /* private methods */
    string parsePattern(string pattern);

    /** Sets expected dimensions (i.e. row height in pixels) based on barcode type */
    void SetDimensions(Image *image, BarcodeType type);

    /** Returns pixel statistics for a given row in image */
    histogramResult VerticalHistogram(Image* image, size_t startingY);

    /** Converts pixel pattern to bit pattern for a given row in image */
    vector<int> ImageToBits(histogramResult *vertHist);

    /** Converts pixel pattern to binary pattern for chunker */
    void PatternToBinary(vector<int> *pattern, vector<int> *binary);

    /** Converts vector to string (todo move :))*/
    string VectorToString(vector<float> *data);
};

#endif // DECODER_H
