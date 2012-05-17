#include "greedyAlgorithm.h"
#include <vector>
#include <string>
#include <map>

using namespace std;



const char GreedyAlgorithm::Letters[alphaSize] = {'e','a','r', 'i', 'o', 't','n','s','l','c','u','d','p',
                                                  'm','h','g','b','f','y','w','k','v','x','z','j','q', ' ',
                                                  '(', ')', '@', '#', '&', '%', '!', '?','.', '+', '=','>','<',
                                                  ':',';','-','_','*','^','$','{','}','/','\'','|','`','~', '[',']'};

const string GreedyAlgorithm::errorString = "Invalid String";

const map<char,int> GreedyAlgorithm::createMap(int version) {
    map<char, int> newMap;
    switch(version){
    case 1:
        for(int i=0; i < alphaSize; i++){
            newMap[Letters[i]] = i;
        }
        break;
    case 2:
        for(int j = 0; j < 10; j++){
            newMap['0' + j] = j;
        }
        for(int i = 0;i < alphaSize; i++) {
            newMap[Letters[i]] = i+10;
        }
        break;
    default:
        break;
    }
    return newMap;

}

string intToString(int num){
    string result = "";
    result += '0' + (num/10);
    result += '0' + (num%10);
    return result;
}

const map<char,int> GreedyAlgorithm::alphaMap = GreedyAlgorithm::createMap(1);
const map<char,int> GreedyAlgorithm::alphaNumericMap = GreedyAlgorithm::createMap(2);

string GreedyAlgorithm::printMap(int version){
    string result = "";
    map<char,int>::const_iterator it;
    map<char,int>::const_iterator end;
    if(version == 1){
        it = alphaMap.begin();
        end = alphaMap.end();
    }else{
        it = alphaNumericMap.begin();
        end = alphaNumericMap.end();
    }
    while(it != end){
        result += it->first;
        result += " ";
        result.append(intToString(it->second));
        result += "\n";
        it++;
    }
    return result;
}

/*
 * Converts the given string from its current representation to a number representation.
 * Conversion is based on the passed in mode parameter.
 */
string GreedyAlgorithm::convertInput(string input, int mode){
    string result = "";
    int num = 0;
    map<char,int>::const_iterator it;
    switch(mode){
    case 0://numeric
        for(int i = 0; i < (int)input.length(); i++){
            if(input.at(i) < '0' || input.at(i) > '9'){
                return errorString;
            }
        }
        return input;
        break;
    case 1://alpha
        for(int i = 0; i < (int)input.length(); i++){
            it = alphaMap.find(input.at(i));
            if(it == alphaMap.end()){
                return errorString;
            }
            num  = it->second;
            result.append(intToString(num));
        }
        break;
    case 2://alphanumeric
        for(int i = 0; i < (int)input.length(); i++){
            it = alphaNumericMap.find(input.at(i));
            if(it == alphaNumericMap.end()){
                return errorString;
                break;
            }
            num  = it->second;
            result.append(intToString(num));
        }
        break;
    default:
        return input;
    }
    return result;
}

string GreedyAlgorithm::integerToString(int num){
    string result = "";
    while(num != 0){
        result += '0' + num%10;
        num /= 10;
    }
    return string(result.rbegin(), result.rend());
}

int GreedyAlgorithm::stringToInteger(string str){
    int num = 0;
    for(int i = 0; i < (int)str.length(); i++){
        num*=10;
        num += str.at(i) - '0';
    }
    return num;
}

string GreedyAlgorithm::greedyHelper(string numberChunk, vector<float>* sequence){

}

void GreedyAlgorithm::setNumberSystem(NumberSystem *sys){
    system = sys;
}

string GreedyAlgorithm::runGreedy(string input, int chunk){
    string result = "";
    vector<float>* sequence = system->getSequence();
    float number = (float)stringToInteger(input.substr(0,chunk));
    for(int i = sequence->size()-1; i >= 0; i--){
        if(number >= sequence->at(i)){
            result += '1';
            number -= sequence->at(i);

        }else{
            result += '0';
        }
    }
    return string(result.rbegin(), result.rend());
}

/*GreedyAlgorithm::GreedyAlgorithm(NumberSystem sys){

}*/
