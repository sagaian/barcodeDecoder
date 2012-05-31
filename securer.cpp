#include <securer.h>
#include <numberSystem.h>
#include <fibonacciSystem.h>
#include <goldenRatioSystem.h>
#include <multiBase.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <iomanip>

using namespace std;

/* private methods */
string Securer::encodeFibonacciPin(int p, int q, int op){
    stringstream ss;
    ss << p << q << op;
    return ss.str();
}

string Securer::encodeGoldenPin(float ratio){
    stringstream ss;
    ss << ratio;
    //encode three digits of decimal part of ratio
    string encoded = ss.str();
    while(encoded.size() < 5){
        encoded += '0';
    }
    return encoded.substr(2,3);

}

void Securer::generateRandomFibonacci(NumberSystem *sys){
    int p, q, op;
    p = rand() % (MAX_P + 1);
    q = rand() % (MAX_Q + 1);
    //op = rand() % 2;
    op = 0;
    Fibonacci f(p, MAX_CHUNK, op);
    *sys = f;
    securePin += '0' + encodeFibonacciPin(p, q, op);
}

void Securer::generateRandomRatio(NumberSystem *sys){
    float ratio = (rand() % MAX_CHUNK + 1.0)/(MAX_CHUNK + 1) + 1; //ie MAX_CHUNK = 999, float values range from 1.001 - 1.999
    GoldenRatio g(MAX_CHUNK, ratio);
    *sys = g;
    securePin += '1' + encodeGoldenPin(ratio);
}

void Securer::generateRandomMultiBase(NumberSystem *sys){
    //int nSystems = (rand() % MAX_SYSTEMS);
    int nSystems = MAX_SYSTEMS;
    vector<NumberSystem> systems;
    for(int i = 0; i < nSystems; i++){
        NumberSystem nextSys;
        //int type = rand() % 2;
        int type =0;
        if(type == 0){
            generateRandomFibonacci(&nextSys);
        } else {
            generateRandomRatio(&nextSys);
        }
        systems.push_back(nextSys);
    }
    MultiBase b(0, &systems);
    *sys = b;
}

void Securer::ratioPinToSystem(string pin, NumberSystem *sys){
    float ratio = atof(pin.c_str())/(MAX_CHUNK + 1) + 1;
    GoldenRatio g(MAX_CHUNK, ratio);
    *sys = g;
}

void Securer::fibonacciPinToSystem(string pin, NumberSystem *sys){
    int p = pin.at(0) - 48;
    int q = pin.at(1) - 48;
    int op = pin.at(2) - 48;
    Fibonacci f(p, MAX_CHUNK, op);
    *sys = f;
}

/* public methods */
Securer::Securer(){
    srand(time(0));
    securePin = "";
}

string Securer::getPin(){
    return securePin;
}

void Securer::generateUnsecuredSystem(NumberSystem *sys){
    Fibonacci f(1, MAX_CHUNK, 0);
    f.sanitizeSequence();
    *sys = f;
}

void Securer::generateLowSecuritySystem(NumberSystem *sys){
    generateRandomFibonacci(sys);
    sys->sanitizeSequence();
}

void Securer::generateHighSecuritySystem(NumberSystem *sys){
    generateRandomMultiBase(sys);
    sys->sanitizeSequence();
}

void Securer::decodePin(string pin, NumberSystem *sys){
    size_t len = pin.size();
    if(len == 0){
        generateUnsecuredSystem(sys);
        return;
    }
    assert(len % 4 == 0);
    vector<NumberSystem> systems;
    for(size_t i = 0; i < len; i+=4){
        NumberSystem nextSys;
        if(pin.at(i) == '0'){
            fibonacciPinToSystem(pin.substr(i+1,3), &nextSys);
        } else {
            ratioPinToSystem(pin.substr(i+1,3), &nextSys);
        }
        systems.push_back(nextSys);
    }
    MultiBase b(0, &systems);
    b.sanitizeSequence();
    *sys = b;
}
