/*
 * fibonacciSystem.h
 */

#ifndef FIBONACCISYSTEM_H_
#define FIBONACCISYSTEM_H_

#include "numberSystem.h"
#include <vector>

class Fibonacci : public NumberSystem {
private:
	/* instance variables */
	int p;
	int op;
	std::vector<int> *fibNumbers;
	/* methods*/
	int getFibNumber(int index);
	void initList();
public:
	Fibonacci(int p);
	Fibonacci(int p, int op);
	~Fibonacci();
	std::vector<int> *generateSequence(int start, int end);
	void changeSystem(int i);
};

#endif /* FIBONACCISYSTEM_H_ */
