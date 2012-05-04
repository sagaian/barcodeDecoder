/*
 * numberSystem.h
 */

#ifndef NUMBERSYSTEM_H_
#define NUMBERSYSTEM_H_

#include <vector>

class NumberSystem {
public:
	virtual std::vector<int> *generateSequence(int start, int end) = 0;
	virtual void changeSystem(int i) = 0;
};

#endif /* NUMBERSYSTEM_H_ */
