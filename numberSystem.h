/*
 * numberSystem.h
 */
#ifndef NUMBERSYSTEM_H_
#define NUMBERSYSTEM_H_
#include <vector>
#include <string>
#define EPSILON .0002

using namespace std;

class NumberSystem {
private:
    float error;
protected:
    /* instance variable */
    vector<float> sequence;
    string description;
public:
    //virtual vector<float> *getSequence() = 0;
    vector<float> *getSequence();
    void sanitizeSequence();
    void getGreedyRepresentation(float number, vector<int> *greedy);
    float getGreedyError();
    string getGreedyAsSum(vector<int> *greedy);
    int getChunkSize();
    void setChunkSize(int size);
    string getDescription();
    NumberSystem();
};

#endif /* NUMBERSYSTEM_H_ */
