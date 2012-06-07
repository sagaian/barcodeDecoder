/*
 * fibonacciSystem.h
 */
using namespace std;
#ifndef FIBONACCISYSTEM_H_
#define FIBONACCISYSTEM_H_

#include "numberSystem.h"
#include <vector>
#include "alphaConverter.h"

class Fibonacci : public NumberSystem {
private:
	/* instance variables */
	//vector<float> *sequence;
	/* methods*/
	void initList(vector<float> *list, int p);
	void generateSequence(int p, int start, int end, int op);
	void generateSequence(int p, int maxValue, int op);
        void setDescription(int p, int op);
public:
	Fibonacci(int p, int maxValue, int op);
	Fibonacci(int p, int start, int end, int op);
	//vector<float> *getSequence();
};

#endif /* FIBONACCISYSTEM_H_ */
