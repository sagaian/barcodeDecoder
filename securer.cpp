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
#include <chunker.h>
#include <math.h>
#include "pqFibonacciSystem.h"
#include "lucasSystem.h"

using namespace std;

/* private methods */
string Securer::encodePQPin(int p, int q){
    stringstream ss;
    ss << p << q;
    return ss.str();
}

string Securer::encodeGoldenPin(float ratio){
    stringstream ss;
    ss << ratio;
    //encode three digits of decimal part of ratio
    string encoded = ss.str();
    while(encoded.size() < PIN_CHUNK + 1){
        encoded += '0';
    }
    return encoded.substr(2,PIN_CHUNK - 1);

}

void Securer::generateRandomFibonacci(NumberSystem *sys){
    int p, q, op;
    p = rand() % (MAX_P + 1 - MIN_P);
    q = rand() % (MAX_Q + 1 - MIN_Q);
    p += MIN_P;
    q += MIN_Q;
    //op = rand() % 2;
    op = 0;
    pqFibonacci f(p,q,Chunker::maxSeqValue, op);
    *sys = f;
    securePin += '0' + encodePQPin(p, q);
}

void Securer::generateRandomLucas(NumberSystem* sys){
    int p, q, op;
    p = rand() % (MAX_P + 1 - MIN_P);
    q = rand() % (MAX_Q + 1 - MIN_Q);
    p += MIN_P;
    q += MIN_Q;
    //op = rand() % 2;
    op = 0;
    Lucas l(p,q,Chunker::maxSeqValue, op);
    *sys = l;
    securePin += '1' + encodePQPin(p, q);
}

void Securer::generateRandomRatio(NumberSystem *sys){
    float ratio = (rand() % Chunker::maxSeqValue + 1.0)/(Chunker::maxSeqValue + 1) + 1; //ie Chunker::maxSeqValue = 999, float values range from 1.001 - 1.999
    GoldenRatio g(Chunker::maxSeqValue, ratio);
    *sys = g;
    securePin += '3' + encodeGoldenPin(ratio);
}

void Securer::generateRandomMultiBase(NumberSystem *sys, int nSystems){
    vector<NumberSystem> systems;
    for(int i = 0; i < nSystems; i++){
        NumberSystem nextSys;
        int type = rand() % NUM_SYSTEMS;
        if(type == 0){
            generateRandomFibonacci(&nextSys);
        } else {
            generateRandomLucas(&nextSys);
            //generateRandomRatio(&nextSys);
        }
        systems.push_back(nextSys);
    }
    MultiBase b(0, &systems);
    *sys = b;
}

void Securer::ratioPinToSystem(string pin, NumberSystem *sys){
    float ratio = atof(pin.c_str())/(Chunker::maxSeqValue + 1) + 1;
    GoldenRatio g(Chunker::maxSeqValue, ratio);
    *sys = g;
}

void Securer::PinToSystem(string pin, NumberSystem *sys){
    int p = pin.at(1) - '0';
    int q = pin.at(2) - '0';
    int op = 0;
    switch(pin.at(0)){
    case '0':
        *sys = pqFibonacci(p,q, Chunker::maxSeqValue, op);
        break;
    case '1':
        *sys = Lucas(p,q, Chunker::maxSeqValue, op);
        break;
    default:
        *sys = pqFibonacci(p,q, Chunker::maxSeqValue, op);
        //ratioPinToSystem(pin.substr(i+1,PIN_CHUNK-1), &nextSys);
    }
}

/* public methods */
Securer::Securer(){
    srand(time(0));
    //srand(3);
    securePin = "";
}

string Securer::getPin(){
    return securePin;
}

void Securer::generateUnsecuredSystem(NumberSystem *sys){
    vector<NumberSystem> unsecuredSequences;//note these cannot be randomly generated as secure sequence
    unsecuredSequences.push_back(pqFibonacci(0, 0,Chunker::maxSeqValue, 0));
    unsecuredSequences.push_back(pqFibonacci(1, 0,Chunker::maxSeqValue, 0));
    unsecuredSequences.push_back(pqFibonacci(1, 0,Chunker::maxSeqValue, 0));
    *sys = MultiBase(0, &unsecuredSequences);
    sys->sanitizeSequence();
}

void Securer::generateLowSecuritySystem(NumberSystem *sys){
    generateRandomMultiBase(sys, MAX_SYSTEMS_SECURE - 1);
    sys->sanitizeSequence();
}

void Securer::generateHighSecuritySystem(NumberSystem *sys){
    generateRandomMultiBase(sys, MAX_SYSTEMS_SECURE);
    sys->sanitizeSequence();
}

void Securer::decodePin(string pin, NumberSystem *sys){
    size_t len = pin.size();
    if(len == 0){
        generateUnsecuredSystem(sys);
        return;
    }
    //assert(len % PIN_CHUNK == 0);
    vector<NumberSystem> systems;
    for(size_t i = 0; i < len; i+=PIN_CHUNK){
        NumberSystem nextSys;
        PinToSystem(pin.substr(i,PIN_CHUNK), &nextSys);
        systems.push_back(nextSys);
    }
    MultiBase b(0, &systems);
    b.sanitizeSequence();
    *sys = b;
}
