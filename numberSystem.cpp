/*
 * numberSystem.cpp
 */
using namespace std;
#include "numberSystem.h"
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>

vector<float> *NumberSystem::getSequence(){
    return &sequence;
}

/*void NumberSystem::sanitizeSequence(vector<float> *seq){
 set<int> uniqueTerms;
 uniqueTerms.insert(0);
 uniqueTerms.insert(1);
 size_t size = seq->size();
 for( size_t i = 0; i < size; ++i ) uniqueTerms.insert( seq->at(i));
 seq->assign( uniqueTerms.begin(), uniqueTerms.end() );
}*/

void NumberSystem::sanitizeSequence(){
    //sort and skip 0 terms
    sort(sequence.begin(), sequence.end());
    int start = 0;
    /* while(true){
        if(sequence->at(start) > 0) break;
        start++;
    }*/

    // extract unique terms from remaining sequence
    size_t size = sequence.size();
    vector<float> uniqueTerms;
    int index = 0;
    uniqueTerms.push_back(sequence.at(start));
    //this is similar to unique(sequence->begin(), sequence->end()), but with an error threshold;
    for(size_t i = start + 1; i < size; i++){
        float nextTerm = sequence.at(i);
        if(nextTerm - uniqueTerms.at(index) > EPSILON){
            index++;
            uniqueTerms.push_back(nextTerm);
        }
    }
    sequence = uniqueTerms;
}

//void NumberSystem::getGreedyRepresentation(float number, vector<int> *greedy){
//    float remaining = number;
//    int size = sequence->size();
//    int greedyTerms[size];
//    for(int i = size - 1; i >= 0; i--){
//        float curr = sequence->at(i);
//        if((curr - remaining) <= EPSILON){
//            greedyTerms[i] = 1;
//            remaining -= curr;
//        } else {
//            greedyTerms[i] = 0;
//        }
//    }
//    greedy->assign(greedyTerms, greedyTerms + size);
//    error = remaining;
//}

void NumberSystem::getGreedyRepresentation(float number, vector<int> *greedy){
    float remaining = number;
    int size = sequence.size();
    int greedyTerms[size];
    for(int i = 0; i < size; i++) greedyTerms[i] = 0;
    if(number == 0){
         greedyTerms[0] = 1;
    }else{
        for(int i = size - 1; i > 0; i--){
            float curr = sequence.at(i);
            if((curr - remaining) <= EPSILON){
                greedyTerms[i] = 1;
                remaining -= curr;
            } else {
                greedyTerms[i] = 0;
            }
        }
    }
    greedy->assign(greedyTerms, greedyTerms + size);
    error = remaining;
}

string NumberSystem::getGreedyAsSum(vector<int> *greedy){
    int nTerms = 0;
    stringstream resultString;
    for(size_t i = 0; i < greedy->size(); i++){
        int nextTerm = greedy->at(i);
        if(nextTerm == 1){
            if(nTerms != 0) resultString << '+';
            resultString << sequence.at(i);
            nTerms++;
        }
    }
    return resultString.str();
}

float NumberSystem::getGreedyError(){
    return error;
}

string NumberSystem::getDescription(){
   return description;
}

NumberSystem::NumberSystem(){
    error = 0;
}
