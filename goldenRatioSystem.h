/*
 * goldenRatioSystem.h
 */
using namespace std;
#ifndef GOLDENRATIOSYSTEM_H_
#define GOLDENRATIOSYSTEM_H_

#include "numberSystem.h"
class GoldenRatio : public NumberSystem {
private:
	void generateSequence(int maxValue, float ratio);
	void generateSequence(int start, int end, float ratio);
public:
	GoldenRatio(int maxValue, float ratio);
	GoldenRatio(int start, int end, float ratio);
};

#endif /* GOLDENRATIOSYSTEM_H_ */
