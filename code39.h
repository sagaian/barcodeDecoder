#ifndef CODE39_H
#define CODE39_H

#include<string>
#include <map>
#include <vector>
#include "alphaConverter.h"

#define CODE39_ERROR1 "INVALID ENCODING"
#define CODE39_ERROR2 "INVALID DECODING"
#define CHARACTERS 44
#define SENTINEL '*'
#define SENTINEL_STRING "NwNnWnWnN"

#define CODE39_N "1"
#define CODE39_n "0"
#define CODE39_W "11"
#define CODE39_w "00"

using namespace std;

class Code39 {
private:
    static const char Characters[CHARACTERS];
    static const char* Strings[CHARACTERS];
    static const map<char,string> encoding;
    static const map<string,char> decoding;

    static const map<char,string> generateEncodingMap();
    static const map<string,char> generateDecodingMap();

    static string stringToBits(string* str);
    static vector<int> stringToBitSequence(string* str);

public:
   static string decodeBarcode(string patternString);
   static vector<int> encodeBarcode(string input);
};
#endif // CODE39_H
