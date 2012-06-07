#include "code39_Encoder.h"

const char Code39::Characters[CHARACTERS] = {'0','1','2','3','4','5','6','7',
                                             '8','9','A','B','C','D','E','F',
                                             'G','H','I','J','K','L','M','N',
                                             'O','P','Q','R','S','T','U','V',
                                             'W','X','Y','Z','-','.',' ','$',
                                             '/','+','%'};

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
                                           "NwWnWnNnN", "WwNnNnWnN", "NwWnNnWnN",
                                           "NwNwNwNnN", "NwNwNnNwN", "NwNnNwNwN",
                                           "NnNwNwNwN"};

const map<char,string> Code39::encoding = Code39::generateEncoding();


const map<char,string> Code39::generateEncoding(){
    map<char,string> mapping;
    for(int i = 0; i < CHARACTERS; i++){
        mapping[Characters[i]] = Strings[i];
    }
    return mapping;
}

vector<int> Code39::encodeBarcode(string input){
    map<char,string>::const_iterator it;
    string currString = "";
    string result = "";
    //check that string contains valid characters
    for(int i = 0; i < (int)input.length(); i++){
        it = encoding.find(input.at(i));
        if(it == encoding.end()){
            return vector<int>();
        }
        currString = it->second;
        currString = stringToBits(&currString);
        result.append(currString);
    }
    return stringToBitSequence(&result);
}

string Code39::stringToBits(string* str){
    string result = "";
    for(unsigned int i = 0; i < str->length(); i++){
        switch(str->at(i)){
        case 'N':
            result.append(N);
            break;
        case 'n':
            result.append(n);
            break;
        case 'W':
            result.append(W);
            break;
        case 'w':
            result.append(w);
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
        bitSequence.push_back('0' + str->at(i));
    }
    return bitSequence;
}
