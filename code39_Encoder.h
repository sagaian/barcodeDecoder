#ifndef CODE39_ENCODER_H
#define CODE39_ENCODER_H

#include<string>
#include <map>
#include <vector>

#define CODE39_ERROR1 "INVALID ENCODING"
#define CODE39_ERROR2 "INVALID DECODING"
#define CHARACTERS 43
#define SENTINEL *
#define SENTINEL_STRING "NwNnWnWnN"

#define N "1"
#define n "0"
#define W "11"
#define w "00"

using namespace std;

class Code39 {
private:
    static const char Characters[CHARACTERS];
    static const char* Strings[CHARACTERS];
    static const map<char,string> encoding;
    static const map<char,string> generateEncoding();

    static string stringToBits(string* str);
    static vector<int> stringToBitSequence(string* str);
public:
   static string decodeBarcode(vector< vector<int> > bits);
   static vector<int> encodeBarcode(string input);
};
#endif // CODE39_ENCODER_H
