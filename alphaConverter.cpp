#include "alphaConverter.h"

const char AlphaConverter::Letters[alphaSize] = {'E','A','R', 'I', 'O', 'T','N','S','L','C','U','D','P',
                                                 'M','H','G','B','F','Y','W','K','V','X','Z','J','Q', ' ', ',', '\n',
                                                 '(', ')', '@', '#', '&', '%', '!', '?','.', '+', '=','>','<', '"',
                                                 ':',';','-','_','*','^','$','{','}','/','\'','|','`','~', '[',']'};

const map<char,int> AlphaConverter::alphaEncodeMap = AlphaConverter::createEncoderMap(1);
const map<char,int> AlphaConverter::alphaNumericEncodeMap = AlphaConverter::createEncoderMap(2);
const map<int,char> AlphaConverter::alphaDecodeMap = AlphaConverter::createDecoderMap(1);
const map<int,char> AlphaConverter::alphaNumericDecodeMap = AlphaConverter::createDecoderMap(2);



const map<char,int> AlphaConverter::createEncoderMap(int version) {
    map<char, int> newMap;
    switch(version){
    case 1:
        for(int i = 0; i < alphaSize; i++){
            newMap[Letters[i]] = i+STARTING_INDEX;
        }
        break;
    case 2:
        for(int j = 0; j < 10; j++){
            newMap['0' + j] = j + STARTING_INDEX;
        }
        for(int i = 0;i < alphaSize; i++) {
            newMap[Letters[i]] = i+10+STARTING_INDEX;
        }
        break;
    default:
        break;
    }
    return newMap;
}

const map<int,char> AlphaConverter::createDecoderMap(int version) {
    map<int, char> newMap;
    switch(version){
    case 1:
        for(int i = 0; i < alphaSize; i++){
            newMap[i+STARTING_INDEX] = Letters[i];
        }
        break;
    case 2:
        for(int j = 0; j < 10; j++){
            newMap[j+STARTING_INDEX] = '0' + j;
        }
        for(int i = 0;i < alphaSize; i++) {
            newMap[i+10+STARTING_INDEX] = Letters[i];
        }
        break;
    default:
        break;
    }
    return newMap;
}

string AlphaConverter::encodeAlpha(string input, int mode){
    string result = "";
    int num = 0;
    input = stringToUpper(input);
    map<char,int>::const_iterator it;
    switch(mode){
    case 0://numeric
        //check that string contains no alpha characters
        for(int i = 0; i < (int)input.length(); i++){
            if(input.at(i) < '0' || input.at(i) > '9'){
                return ERROR_STRING1;
            }
        }
        return input;
    case 1://alpha
        //check that string contains valid characters
        for(int i = 0; i < (int)input.length(); i++){
            it = alphaEncodeMap.find(input.at(i));
            if(it == alphaEncodeMap.end()){
                return ERROR_STRING1;
            }
            num  = it->second;
            result.append(adjustStringSize(integerToString(num)));
        }
        break;
    case 2://alphanumeric
        //check that string contains valid characters
        for(int i = 0; i < (int)input.length(); i++){
            it = alphaNumericEncodeMap.find(input.at(i));
            if(it == alphaNumericEncodeMap.end()){
                return ERROR_STRING1;
                break;
            }
            num  = it->second;
            result.append(adjustStringSize(integerToString(num)));
        }
        break;
    default:
        return input;
    }
    return result;
}

/*
 * Converts a string from a number representation to another depending on the mode
 * selected.
 * mode = 0 Numeric -> Numeric
 * mode = 1 Numeric -> Alpha
 * mode = 2 Numeric -> AlphaNumeric
 */
string AlphaConverter::decodeAlpha(string input, int mode){
    string result = "";
    char ch = 0;
    string curr = "";
    map<int,char>::const_iterator it;
    switch(mode){
    case 0://numeric
        return input;
    case 1://alpha
        //if we cannot divide string evenly, it cannot be decoded.
        if(input.length() % ENCODING_SIZE != 0){
            return ERROR_STRING2;
        }

        for(unsigned int i = 0; i < input.length(); i += ENCODING_SIZE){
            curr = input.substr(i, ENCODING_SIZE);
            it = alphaDecodeMap.find(stringToInteger(curr));
            if(it == alphaDecodeMap.end()){
                return ERROR_STRING2;
            }
            ch  = it->second;
            result += ch;
        }
        break;

    case 2://alphanumeric
        if(input.length() % ENCODING_SIZE != 0){
            return ERROR_STRING2;
        }

        for(unsigned int i = 0; i < input.length(); i += ENCODING_SIZE){
            curr = input.substr(i, ENCODING_SIZE);
            it = alphaNumericDecodeMap.find(stringToInteger(curr));
            if(it == alphaNumericDecodeMap.end()){
                return ERROR_STRING2;
                break;
            }
            ch  = it->second;
            result += ch;
        }
        break;

    default:
        return input;
    }
    return result;
}

string AlphaConverter::bitSequenceToString(vector< vector<int> > bits){
    string result = "";
    for(unsigned int i = 0; i < bits.size() ; i++){
        for(unsigned int j = 0; j < bits[i].size(); j++){
            result += '0' + bits[i][j];
        }
    }
    return result;
}

string AlphaConverter::adjustStringSize(string str){
    string adjustmentString = "";
    int adjustment = str.length()%ENCODING_SIZE;
    if(adjustment == 0){
        return str;
    }
    for(int i = 0; i <adjustment; i++){
        adjustmentString += '0';
    }
    return adjustmentString.append(str);
}

string AlphaConverter::integerToString(int num){
    string result = "";
    while(num != 0){
        result += '0' + num%10;
        num /= 10;
    }
    return string(result.rbegin(), result.rend());
}

int AlphaConverter::stringToInteger(string str){
    int num = 0;
    for(int i = 0; i < (int)str.length(); i++){
        num*=10;
        num += str.at(i) - '0';
    }
    return num;
}

string AlphaConverter::stringToUpper(string str){
    string result = "";
    char currChar = 0;
    for(unsigned int i = 0; i < str.length(); i++){
        currChar = str.at(i);
        if(currChar >= 'a' && currChar <= 'z'){
            currChar = 'A' + (currChar - 'a');
        }
        result += currChar;
    }
    return result;
}

string AlphaConverter::floatToString(float num){
    stringstream str;
    str << num;
    return str.str();
}
