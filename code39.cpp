#include "code39.h"

const char Code39::Characters[CHARACTERS] = {'0','1','2','3','4','5','6','7',
                                             '8','9','A','B','C','D','E','F',
                                             'G','H','I','J','K','L','M','N',
                                             'O','P','Q','R','S','T','U','V',
                                             'W','X','Y','Z','-','.',' ','$',
                                             '/','+','%',SENTINEL};

const char* Code39::Strings[CHARACTERS] = {"NnNwWnWnN", "WnNwNnNnW", "NnWwNnNnW",
                                           "WnWwNnNnN", "NnNwWnNnW", "WnNwWnNnN",
                                           "NnWwWnNnN", "NnNwNnWnW", "WnNwNnWnN",
                                           "NnWwNnWnN", "WnNnNwNnW", "NnWnNwNnW",
                                           "WnWnNwNnN", "NnNnWwNnW", "WnNnWwNnN",
                                           "NnWnWwNnN", "NnNnNwWnW", "WnNnNwWnN",
                                           "NnWnNwWnN", "NnNnWwWnN", "WnNnNnNwW",
                                           "NnWnNnNwW", "WnWnNnNwN", "NnNnWnNwW",
                                           "WnNnWnNwN", "NnWnWnNwN", "NnNnNnWwW",
                                           "WnNnNnWwN", "NnWnNnWwN", "NnNnWnWwN",
                                           "WwNnNnNnW", "NwWnNnNnW", "WwWnNnNnN",
                                           "NwNnWnNnW", "WwNnWnNnN", "NwWnWnNnN",
                                           "NwNnNnWnW", "WwNnNnWnN", "NwWnNnWnN",
                                           "NwNwNwNnN", "NwNwNnNwN", "NwNnNwNwN",
                                           "NnNwNwNwN",SENTINEL_STRING};

const map<char,string> Code39::encoding = Code39::generateEncodingMap();
const map<string,char> Code39::decoding = Code39::generateDecodingMap();

const map<char,string> Code39::generateEncodingMap(){
    map<char,string> mapping;
    for(int i = 0; i < CHARACTERS; i++){
        mapping[Characters[i]] = Strings[i];
    }
    return mapping;
}

const map<string, char> Code39::generateDecodingMap(){
    map<string,char> mapping;
    for(int i = 0; i < CHARACTERS; i++){
        mapping[Strings[i]] = Characters[i];
    }
    return mapping;
}

string Code39::stringToBits(string* str){
    string result = "";
    for(unsigned int i = 0; i < str->length(); i++){
        switch(str->at(i)){
        case 'N':
            result.append(CODE39_N);
            break;
        case 'n':
            result.append(CODE39_n);
            break;
        case 'W':
            result.append(CODE39_W);
            break;
        case 'w':
            result.append(CODE39_w);
            break;
        default:
            break;
        }
    }
    return result;
}

vector<int> Code39::stringToBitSequence(string *str){
    vector<int> bitSequence;
    for(unsigned int i = 0; i < str->length(); i++){
        bitSequence.push_back(str->at(i) - '0');
    }
    return bitSequence;
}


vector<int> Code39::encodeBarcode(string input){
    input = AlphaConverter::stringToUpper(input);
    input.insert(input.begin(),SENTINEL);
    input += SENTINEL;
    map<char,string>::const_iterator it;
    string currString = "";
    string result = "";
    //check that string contains valid characters
    for(unsigned int i = 0; i < input.length(); i++){
        it = encoding.find(input.at(i));
        if(it == encoding.end()){
            return vector<int>();
        }
        currString = it->second;
        if(i != input.length()-1){
            currString += 'n';
        }
        currString = stringToBits(&currString);
        result.append(currString);
    }
    return stringToBitSequence(&result);
}

string Code39::decodeBarcode(string patternString){
    //return patternString;
    string result = "";
    string curr = "";
    map<string,char>::const_iterator it;
    for(size_t i=0; i<patternString.length(); i+=10)
    {
        curr = patternString.substr(i, 9);
        it = decoding.find(curr);
        if(it == decoding.end()){
            return CODE39_ERROR2;
        }else{
            result += it->second;
        }
    }
    return result;
}
