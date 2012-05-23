#include <Magick++.h>
#include <enhancer.h>
#include "numberSystem.h"
#include <sstream>
#include <vector>
#include <math.h>
#include <assert.h>
#include "goldenRatioSystem.h"
using namespace std;
using namespace Magick;

// concats dimensions as string
string Enhancer::getDimensions(size_t ncols, size_t nrows){
    stringstream s;
    s << ncols << "x" << nrows;
    return s.str();
}

// PLIP scaling
float Enhancer::PlipGt(float pixel){
    return MU-1-pixel;
}

// PLIP phi transform
float Enhancer::PlipPhi(float pixel){
    return -LAMDA*pow((log(1-pixel/LAMDA)),BETA);
}

// PLIP inverse phi transform
float Enhancer::PlipInvPhi(float pixel){
    return LAMDA*(1-exp(pow(-pixel/LAMDA,(1/BETA))));
}

// PLIP multiplication
float Enhancer::PlipMulp(float pixel1, float pixel2){
    return PlipInvPhi(PlipPhi(pixel1) * PlipPhi(pixel2));
}


// split pixel value into lower and upper half (as determined by threshold), returns lower
float Enhancer::SplitPixel(float pixel, NumberSystem *s, size_t nTerms, size_t threshold){
    vector<float> *seq = s->getSequence();
    vector<int> greedy;
    s->getGreedyRepresentation(pixel, &greedy);
    float lowerTotal = 0;
    for(size_t i = 0; i < threshold; i++){
        int nextTerm = greedy.at(i);
        if(nextTerm == 1){
            lowerTotal += seq->at(i);
        }
    }
    return lowerTotal;
}

// enhances image using PLIP multiplication of two sub images
void Enhancer::EnhanceImage(Image image, NumberSystem *sys){
    size_t nrows = image.rows();
    size_t ncolumns = image.columns();
    size_t nterms = sys->getSequence()->size();
    size_t midpt = nterms*.5;

    image.modifyImage();
    PixelPacket *pixel_cache = image.getPixels(0,0,ncolumns,nrows);
    float min, max;
    float mulp[nrows][ncolumns];

    // split upper and lower pixels into two images
    for(size_t row = 0; row < nrows ; row++){
        for(size_t col = 0; col < ncolumns; col++){
            PixelPacket *pixel = pixel_cache + row*ncolumns + col;
            float pixel256 = pixel->blue/256.0;
            float lower = SplitPixel(pixel256, sys, nterms, midpt);
            float upper = pixel256 - lower;
            float product = PlipGt(PlipMulp(PlipGt(upper), PlipGt(lower)));
            if(row == 0 && col == 0){
                min = product;
                max = product;
            } else {
                if(product < min) min = product;
                if(product > max) max = product;
            }
            mulp[row][col] = product;
        }
    }

    // enhance image using PLIP multiplication
    Image enhanced(getDimensions(ncolumns,nrows), "white");
    enhanced.modifyImage();
    PixelPacket *enhanced_pixel_cache = enhanced.getPixels(0,0,ncolumns,nrows);
    for(size_t row = 0; row < nrows ; row++){
        for(size_t col = 0; col < ncolumns; col++){
            assert(max != min);
            float pixel8= 255*(mulp[row][col] - min)/ (max - min);
            float pixel16 = pixel8 * 256;
            assert(pixel16 <= MAX_VALUE * 256);
            PixelPacket *pixel = enhanced_pixel_cache + row*ncolumns + col;
            pixel->blue = pixel16;
            pixel->red = pixel16;
            pixel->green = pixel16;
        }
    }

    // Save changes to underlying image .
    enhanced.syncPixels();
    // Save updated image to file.
    enhanced.write("enhanced.gif");
}

