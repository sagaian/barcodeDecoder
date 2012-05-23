#include <encoder.h>
#include <Magick++.h>
#include <vector>
#include <sstream>

using namespace std;
using namespace Magick;

// concats dimensions as string
string Encoder::getDimensions(size_t ncols, size_t nrows){
    stringstream s;
    s << ncols << "x" << nrows;
    return s.str();
}

string Encoder::VectorToString(vector<int> *data){
    stringstream resultString;
    for(size_t i = 0; i < data->size(); i++){
        resultString << data->at(i);
    }
    return resultString.str();
}

/** barcode starts with black and white bar, then bit pattern, then white, black bar*/
void Encoder::EncodeBinary(vector<int> *binary, string path){
    size_t ncolumns = binary->size() + 4; //binary bits and starting/ending black and white bars
    size_t nrows = 98;
    Image encoded(getDimensions(ncolumns,nrows), "white");
    encoded.modifyImage();
    PixelPacket *encoded_pixel_cache = encoded.getPixels(0,0,ncolumns,nrows);
    for(size_t row = 0; row < nrows; row++){
        for(size_t col = 0; col < ncolumns; col++){
            if(col == 0 || col == ncolumns -1 || (col != 1 && col != ncolumns -2 && binary->at(col - 2) == 1)){
                PixelPacket *pixel = encoded_pixel_cache + row*ncolumns + col;
                pixel->blue = 0;
                pixel->red = 0;
                pixel->green = 0;
            }
        }
    }

    // Save changes to underlying image .
    encoded.syncPixels();
    // Save updated image to file.
    encoded.write("encoded.gif");
}
