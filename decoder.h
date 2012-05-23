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

using namespace std;
using namespace Magick;

class Decoder {
private:
    string parsePattern(string pattern);
    histogramResult VerticalHistogram(Image* image);
    vector<float> BitsToData(vector<int> pattern, NumberSystem *sys);
    string VectorToString(vector<float> *data);
    vector<int> ImageToBits(Image* image);
public:
    string ReadCode39(Image* image);
    string ReadFusion(Image* image, NumberSystem *sys);
};

#endif // DECODER_H
