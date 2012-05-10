/*
 * numberSystem.cpp
 */

using namespace std;
#include "numberSystem.h"
#include "fibonacciSystem.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>

void Fibonacci::initList(vector<float> *list, int p){
	//Any p-Fibonacci sequence begins with 0 followed by p+1 1's and 2.
	list->push_back(0);
	for(int i = 0; i <= p; i++){
		list->push_back(1);
	}
	list->push_back(2);
}

//Generates an ArrayList with the Fibonacci sequence between index start and index end.
void Fibonacci::generateSequence(int p, int start, int end, int op){
	assert(start > 0);
	vector<float> list; // all possible terms in sequence till specified end
	initList(&list, p);
	if(p == 0){
		//Special case for p = 0 which generates the base-2 number system.
		for(int a = 3+p; a <= end; a++){
			list.push_back(pow(2, a -1));
		}
	} else {
		//A fibonacci number the sum (product) of the number before
		//it and the number p+1 spots behind it.
		for(int i = 3+p; i <= end; i++){
			int num1 = list.at(i - 1);
			int num2 = list.at(i - 1 - p);
			if(op == 0){
				list.push_back(num1 + num2);
			} else if (op == 1){
				list.push_back(num1 * num2);
			}
		}
	}
	for(int j = start - 1; j < end; j++){
		sequence->push_back(list.at(j));
	}
}

// generate all possible terms in sequence less than or equal to maxValue
void Fibonacci::generateSequence(int p, int maxValue, int op){
	initList(sequence, p);
	if(p == 0){
		//Special case for p = 0 which generates the base-2 number system.
		int a = 3 + p;
		while(true){
			float nextTerm = pow(2, a -1);
			if(nextTerm > maxValue) break;
			sequence->push_back(nextTerm);
			a++;
		}
	} else {
		//A fibonacci number the sum (product) of the number before
		//it and the number p+1 spots behind it.
		int i = 3 + p;
		while(true){
			float nextTerm;
			float num1 = sequence->at(i - 1);
			float num2 = sequence->at(i - 1 - p);
			if(op == 0){
				nextTerm = num1 + num2;
			} else {
				nextTerm = num1 * num2;
			}
			if(nextTerm > maxValue) break;
			sequence->push_back(nextTerm);
			i++;
		}
	}
}

/*vector<float> *Fibonacci::getSequence(){
	return sequence;
}*/

Fibonacci::Fibonacci(int p, int maxValue, int op){
	generateSequence(p, maxValue, op);
}

Fibonacci::Fibonacci(int p, int start, int end, int op){
	//sequence = new vector<float>();
	if(op >= 0 && op < 2){
		generateSequence(p, start, end, op);
	} else {
		cout << "Invalid operator, default used" << endl;
		generateSequence(p, start, end, 0);
		//exit(1);
	}

}

