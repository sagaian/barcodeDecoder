#ifndef ALPHACONVERTER_H
#define ALPHACONVERTER_H

#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

#define ENCODING_SIZE 2
#define STARTING_INDEX 10
#define ERROR_STRING1 "CANNOT ENCODE"
#define ERROR_STRING2 "CANNOT DECODE"

class AlphaConverter {
private:
    static const int alphaSize = 59;
    static const char Letters[alphaSize];
    static const map<char,int> createEncoderMap(int version);
    static const map<int,char> createDecoderMap(int version);
    static const map<char,int> alphaEncodeMap;
    static const map<char,int> alphaNumericEncodeMap;
    static const map<int, char> alphaDecodeMap;
    static const map<int,char> alphaNumericDecodeMap;

    static string adjustStringSize(string str);
    static string stringToUpper(string str);
public:
    static string integerToString(int num);
    static int stringToInteger(string str);

    static string encodeAlpha(string input, int mode);
    static string decodeAlpha(string input, int mode);
    static string bitSequenceToString(vector< vector<int> > bits);
    static string floatToString(float num);
};
#endif // ALPHACONVERTER_H
