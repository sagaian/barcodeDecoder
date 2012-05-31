#include <encoder.h>
#include <Magick++.h>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;
using namespace Magick;

void Encoder::setDimensions(size_t binarySize, BarcodeType type){
    if(type == OneDimensional){
        ncolumns = binarySize + EXTRA_MODULES; //binary bits and starting/ending black and white bars
        nrows = 1;
        moduleHeight = ONE_D_HEIGHT;
        moduleWidth = ONE_D_WIDTH;
    } else {
        nrows = ceil(sqrt(binarySize));
        ncolumns = nrows + EXTRA_MODULES; //takes into account starting black, white modules and ending white black modules
        moduleHeight = TWO_D_HEIGHT;
        moduleWidth = TWO_D_WIDTH;
    }
}

string Encoder::getDimensions(){
    stringstream s;
    s << ncolumns*moduleWidth << "x" << nrows*moduleHeight; // concats dimensions as string
    return s.str();
}

void Encoder::getPaddedBinary(vector<int> *binary, vector<int> *paddedBinary){
    size_t index = 0;
    for(size_t i = 0; i < nrows; i++){
        for(size_t j = 0; j < ncolumns - EXTRA_MODULES; j++){
            if(index < binary->size()){
                paddedBinary->push_back(binary->at(index));
            } else {
                paddedBinary->push_back(0);
                cout<<"pushed"<<endl;
            }
            index++;
        }
    }
}

string Encoder::VectorToString(vector<int> *data){
    stringstream resultString;
    for(size_t i = 0; i < data->size(); i++){
        resultString << data->at(i);
    }
    return resultString.str();
}

void Encoder::encodeRow(PixelPacket *cache, vector<int> *rowBinary){
    for(size_t row = 0; row < moduleHeight; row++){
        for(size_t col = 0; col < ncolumns; col++){
            if(col == 0 || col == ncolumns -1 || (col != 1 && col != ncolumns -2 && rowBinary->at(col - 2) == 1)){
                for(size_t x = 0; x < moduleWidth; x++){
                    PixelPacket *pixel = cache + row*ncolumns*moduleWidth + col*moduleWidth + x;
                    pixel->blue = 0;
                    pixel->red = 0;
                    pixel->green = 0;
                }
            }
        }
    }
}

void Encoder::encodeMultipleRows(PixelPacket *cache, vector<int> *binary){
    //pad sequence with zeros if necessary
    vector<int> paddedBinary;
    getPaddedBinary(binary, &paddedBinary);

    //encode row by row by splitting up binary into subvectors with range of nBinaryColumns
    for(size_t row = 0; row < nrows; row++){
        PixelPacket *nextRowCache = cache + row*ncolumns*moduleWidth*moduleHeight;
        size_t nBinaryColumns = ncolumns-4; //ncolumns that contain binary info and not start/end modules
        size_t rowIndexStart = row*nBinaryColumns;
        size_t rowIndexEnd = rowIndexStart + nBinaryColumns;
        vector<int> rowBinary(paddedBinary.begin() + rowIndexStart, paddedBinary.begin() + rowIndexEnd);
        encodeRow(nextRowCache, &rowBinary);
    }
}

/* barcode starts with black and white bar, then bit pattern, then white, black bar*/
void Encoder::EncodeBinary(vector<int> *binary, string path, BarcodeType type){
    //set dimensions
    size_t binarySize = binary->size();
    if(type == OneDimensional){
        setDimensions(binarySize, OneDimensional);
    } else {
        setDimensions(binarySize, TwoDimensional);
    }

    //create image and modules
    Image encoded(getDimensions(), "white");
    encoded.modifyImage();
    PixelPacket *encodedPixelCache = encoded.getPixels(0,0,ncolumns*moduleWidth,nrows*moduleHeight);
    if(type == OneDimensional){
        encodeRow(encodedPixelCache, binary);
    } else {
        encodeMultipleRows(encodedPixelCache, binary);
    }

    //save changes to underlying image
    encoded.syncPixels();
    encoded.write(path);
}


