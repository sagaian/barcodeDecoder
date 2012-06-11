#include "pqFibonacciSystem.h"

using namespace std;

void pqFibonacci::initList(vector<float> *list, int p, int q){
    //Any p-Fibonacci sequence begins with 0 followed by p+1 1's and 2.
    list->push_back(0);
    for(int i = 0; i <= (p+q); i++){
        list->push_back(1);
    }
}

//Generates an ArrayList with the Fibonacci sequence between index start and index end.
void pqFibonacci::generateSequence(int p, int q, int start, int end, int op){
    vector<float> list; // all possible terms in sequence till specified end
    float num1 = 0;
    float num2 = 0;
    initList(&list, p, q);
    for(int i = (p+q+1); i < end; i++){
        num1 = list[i-q];
        num2 = list[i-q-p];
        if(op == 0){
            list.push_back(num1 + num2);
        }else if(op == 1){
            list.push_back(num1*num2);
        }
    }

    for(int j = start - 1; j < end; j++){
        sequence.push_back(list.at(j));
    }
}

// generate all possible terms in sequence less than or equal to maxValue
void pqFibonacci::generateSequence(int p, int q, int maxValue, int op){
    initList(&sequence, p, q);
    float num1 = 0;
    float num2 = 0;
    float currTerm = 0;
    int i = (p+q+1);
    while(true){
        num1 = sequence[i-q];
        num2 = sequence[i-q-p];
        if(op == 0){
            currTerm = num1 + num2;
        }else if(op == 1){
            currTerm = num1 * num2;
        }
        if(currTerm > maxValue) break;
        sequence.push_back(currTerm);
        i++;
    }
}

void pqFibonacci::setDescription(int p, int q, int op){
    description = "{pqFibonacci: p = ";
    description.append(AlphaConverter::integerToString(p));
    description.append(", q = ");
    description.append(AlphaConverter::integerToString(q));
    description.append(", op = ");
    if(op == 0){
        description += '+';
    }else{
        description += "*";
    }
    description += '}';
}

/*vector<float> *Fibonacci::getSequence(){
 return sequence;
}*/

pqFibonacci::pqFibonacci(int p, int q, int maxValue, int op){
    setDescription(p, q, op);
    generateSequence(p, q, maxValue, op);
}

pqFibonacci::pqFibonacci(int p, int q, int start, int end, int op){
    setDescription(p, q, op);
    if(op >= 0 && op < 2){
        generateSequence(p, q, start, end, op);
    } else {
        cout << "Invalid operator, default used" << endl;
        generateSequence(p, q, start, end, 0);
        //exit(1);
    }

}

