
#include "powerSystem.h"

using namespace std;

void Power::initList(vector<float> *list){
    //Any p-Fibonacci sequence begins with 0 followed by p+1 1's and 2.
    list->push_back(0);
}

//Generates an ArrayList with the Fibonacci sequence between index start and index end.
void Power::generateSequence(int p, int start, int end){
    initList(&sequence);
    for(int j = start - 1; j < end-1; j++){
        sequence.push_back(pow(p,j));
    }
}

// generate all possible terms in sequence less than or equal to maxValue
void Power::generateSequence(int p, int maxValue){
    float currTerm = 0;
    int i = 0;
    initList(&sequence);
    if(p == 0 || p == 1){
        sequence.push_back(1.);
        return;
    }
    while(true){
        currTerm = pow(p,i);
        if(currTerm > maxValue) break;
        sequence.push_back(currTerm);
        i++;
    }
}

void Power::setDescription(int p){
    description = "{Power: p = ";
    description.append(AlphaConverter::integerToString(p));
    description += '}';
}

/*vector<float> *Fibonacci::getSequence(){
 return sequence;
}*/

Power::Power(int p,int maxValue){
    setDescription(p);
    generateSequence(p, maxValue);
}

Power::Power(int p, int start, int end){
    setDescription(p);
    generateSequence(p,start, end);

}

