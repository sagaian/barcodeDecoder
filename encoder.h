#ifndef ENCODER_H
#define ENCODER_H

#include <vector>
#include <string>
#include <Magick++.h>
using namespace std;
using namespace Magick;

#define ONE_D_WIDTH 1 // width (pixels) of 1D white/black bar
#define ONE_D_HEIGHT 98 // height (pixels) of 1D white/black bar
#define TWO_D_WIDTH 5 // width (pixels) of 2D white/black bar
#define TWO_D_HEIGHT 5 // height (pixels) of 2D white/black bar
#define EXTRA_MODULES  4 // number of modules to encode start/end of each row

class Encoder {

public:
    /** Barcode encoding currently supported */
    enum BarcodeType{
        OneDimensional,
        TwoDimensional
    };

    /** Encodes binary string to a certain path based on barcode type */
    void EncodeBinary(vector<int> *binary, string path, BarcodeType type);
    /** Converts vector to string - todo: move :) */
    string VectorToString(vector<int> *data);

private:
    // private instance variables
    size_t moduleHeight; //height (pixels) of one white/black bar
    size_t moduleWidth;  //width (pixels) of one white/black bar
    size_t nrows; // number of rows with moduleHeight
    size_t ncolumns; // number of columns with moduleWidth

    //private methods
    /**
    * Determines and sets the dimensions of barcode based on the
    * amount of data to be encoded and the barcode type.
    */
    void setDimensions(size_t binarySize, BarcodeType type);

    /** Returns dimensions of barcodes (pixels) as string */
    string getDimensions();

    /**
    * Pads binary data string with zeros in order to encode
    * 2D barcode in rectangular form. The padded binary string is stored in
    * paddedBinary.
    */
    void getPaddedBinary(vector<int> *binary, vector<int> *paddedBinary);

    /**
    * Encodes single row of barcode following the pattern:
    * black bar + white bar + data + white bar + black bar
    */
    void encodeRow(PixelPacket *cache, vector<int> *rowBinary);

    /** Encodes multiples rows by "stacking" single rows on top of each other.
      * Used for two dimensional encoding.
      */
    void encodeMultipleRows(PixelPacket *cache, vector<int> *binary);
};


#endif // ENCODER_H
