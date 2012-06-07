#ifndef SECURER_H
#define SECURER_H
#include <string>
#include <numberSystem.h>

#define MAX_SYSTEMS 3 // number of systems up to and including MAX_SYSTEMS
#define MAX_P 9 //values of p up to and including MAX_P, i.e MAX_P = 2 allows p = 0,1,2
#define MAX_Q 9 //values of q up to and including MAX_Q
#define PIN_CHUNK 4

class Securer{
private:
    string securePin;
    string encodeFibonacciPin(int p, int q, int op);
    string encodeGoldenPin(float ratio);
    void generateRandomFibonacci(NumberSystem *sys);
    void generateRandomRatio(NumberSystem *sys);
    void generateRandomMultiBase(NumberSystem *sys, int nSystems);
    void ratioPinToSystem(string pin, NumberSystem *sys);
    void fibonacciPinToSystem(string pin, NumberSystem *sys);
public:
    Securer();
    string getPin();
    void generateUnsecuredSystem(NumberSystem *sys);
    void generateLowSecuritySystem(NumberSystem *sys);
    void generateHighSecuritySystem(NumberSystem *sys);
    void decodePin(string pin, NumberSystem *sys);
};

#endif // SECURER_H
