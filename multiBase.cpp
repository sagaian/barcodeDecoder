/*
 * multiBase.cpp
 */

using namespace std;
#include "numberSystem.h"
#include "multiBase.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdarg.h>
#include <assert.h>

void MultiBase::FuseSystem(NumberSystem *sys, int op){
    vector<float> newSequence;
    vector<float> *seq = sys->getSequence();
    if(op == 0){
        for(size_t i = 0; i < sequence.size(); i++){
            for(size_t j = 0; j < seq->size(); j++){
                newSequence.push_back(sequence.at(i) + seq->at(j));
            }
        }
    } else {
        for(size_t i = 0; i < sequence.size(); i++){
            for(size_t j = 0; j < seq->size(); j++){
                newSequence.push_back(sequence.at(i) * seq->at(j));
            }
        }
    }
    sequence = newSequence;
}

void MultiBase::setDescription(int op, vector<NumberSystem> *systems){
    description = "MultiBase: op = ";
    if(op == 0){
        description += '+';
    }else{
        description += '*';
    }
    for(size_t i = 0; i < systems->size(); i++){
        description.append(" : ");
        description.append((systems->at(i)).getDescription());
    }
}

MultiBase::MultiBase(int op, vector<NumberSystem>* systems){
    setDescription(op, systems);
    for(int i = 0; i < (int)systems->size(); ++i ){
        NumberSystem *s = &(systems->at(i));
        if(i == 0){
            sequence = *s->getSequence();
        } else {
            FuseSystem(s, op);
        }
    }
}




