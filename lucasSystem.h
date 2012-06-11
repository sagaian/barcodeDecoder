#ifndef LUCASSYSTEM_H
#define LUCASSYSTEM_H

#include "numberSystem.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include "alphaConverter.h"

class Lucas : public NumberSystem {
private:
        /* instance variables */
        //vector<float> *sequence;
        /* methods*/
        void initList(vector<float> *list, int p, int q);
        void generateSequence(int p, int q, int start, int end, int op);
        void generateSequence(int p, int q,  int maxValue, int op);
        void setDescription(int p, int q, int op);
public:
        Lucas(int p, int q, int maxValue, int op);
        Lucas(int p, int q, int start, int end, int op);
        //vector<float> *getSequence();
};
#endif // LUCASSYSTEM_H
