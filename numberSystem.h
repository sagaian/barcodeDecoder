/*
 * numberSystem.h
 */

using namespace std;
#ifndef NUMBERSYSTEM_H_
#define NUMBERSYSTEM_H_
#include <vector>

#define EPSILON .002

class NumberSystem {
private:
	float error;
protected:
	/* instance variable */
	vector<float> *sequence;
public:
	//virtual vector<float> *getSequence() = 0;
	vector<float> *getSequence();
	void sanitizeSequence();
	void getGreedyRepresentation(float number, vector<int> *greedy);
	float getGreedyError();
	void printGreedyAsString(vector<int> *greedy);
	NumberSystem();
};

#endif /* NUMBERSYSTEM_H_ */
