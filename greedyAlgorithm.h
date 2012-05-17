#ifndef GREEDYALGORITHM_H
#define GREEDYALGORITHM_H

#include <vector>
#include <string>
#include <map>
#include "numberSystem.h"

using namespace std;

class GreedyAlgorithm{
private:
    static const int alphaSize = 56;
    static const char Letters[alphaSize];
    static const map<char,int> createMap(int version);
    static const map<char,int> alphaMap;
    static const map<char,int> alphaNumericMap;
    NumberSystem* system;
    string greedyHelper(string numberChunk, vector<float>* sequence);

public:
    static const string errorString;
    string convertInput(string input, int mode);
    string runGreedy(string input, int chunk);
    string printMap(int version);
    void setNumberSystem(NumberSystem* sys);
    static string integerToString(int num);
    static int stringToInteger(string str);
};

#endif // GREEDYALGORITHM_H
