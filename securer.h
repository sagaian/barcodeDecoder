#ifndef SECURER_H
#define SECURER_H
#include <string>
#include <numberSystem.h>

#define MAX_SYSTEMS 3
#define MAX_SYSTEMS_SECURE 2 // number of systems up to and including MAX_SYSTEMS
#define NUM_SYSTEMS 2
#define MIN_P 1
#define MIN_Q 0
#define MAX_P 9 //values of p up to and including MAX_P, i.e MAX_P = 2 allows p = 0,1,2
#define MAX_Q 5 //values of q up to and including MAX_Q
#define PIN_CHUNK 3

class Securer{
private:
    string securePin;
    string encodePQPin(int p, int q);
    string encodeGoldenPin(float ratio);
    void generateRandomFibonacci(NumberSystem *sys);
    void generateRandomLucas(NumberSystem *sys);
    void generateRandomRatio(NumberSystem *sys);
    void generateRandomMultiBase(NumberSystem *sys, int nSystems);
    void ratioPinToSystem(string pin, NumberSystem *sys);
    void PinToSystem(string pin, NumberSystem *sys);
public:
    Securer();
    string getPin();
    void generateUnsecuredSystem(NumberSystem *sys);
    void generateLowSecuritySystem(NumberSystem *sys);
    void generateHighSecuritySystem(NumberSystem *sys);
    void decodePin(string pin, NumberSystem *sys);
};

#endif // SECURER_H
