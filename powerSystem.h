#ifndef POWERSYSTEM_H
#define POWERSYSTEM_H
#include "numberSystem.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include "alphaConverter.h"

class Power : public NumberSystem {
private:
        /* instance variables */
        //vector<float> *sequence;
        /* methods*/
        void initList(vector<float> *list);
        void generateSequence(int p, int start, int end);
        void generateSequence(int p, int maxValue);
        void setDescription(int p);
public:
        Power(int p, int maxValue);
        Power(int p, int start, int end);
        //vector<float> *getSequence();
};
#endif // POWERSYSTEM_H
