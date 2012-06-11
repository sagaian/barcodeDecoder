#ifndef PQFIBONACCISYSTEM_H
#define PQFIBONACCISYSTEM_H

#include "numberSystem.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include "alphaConverter.h"

class pqFibonacci : public NumberSystem {
private:
        /* instance variables */
        //vector<float> *sequence;
        /* methods*/
        void initList(vector<float> *list, int p, int q);
        void generateSequence(int p, int q, int start, int end, int op);
        void generateSequence(int p, int q,  int maxValue, int op);
        void setDescription(int p, int q, int op);
public:
        pqFibonacci(int p, int q, int maxValue, int op);
        pqFibonacci(int p, int q, int start, int end, int op);
        //vector<float> *getSequence();
};
#endif // PQFIBONACCISYSTEM_H
