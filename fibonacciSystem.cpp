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

//helper to generate fib sequences
void Fibonacci::initList(){
	//Any p-Fibonacci sequence begins with 0 followed by p+1 1's.
	fibNumbers->clear();
	fibNumbers->push_back(0);
	for(int i = 0; i <= p; i++){
		fibNumbers->push_back(1);
	}
}

void Fibonacci::changeSystem(int p){
	Fibonacci::p = p;
	initList();
}

//Generates an ArrayList with the Fibonacci sequence
//between index start and index end.
vector<int> *Fibonacci::generateSequence(int start, int end){
	assert(start > 0);
	vector<int> *result = new vector<int>();
	if(p == 0){
		//Special case for p = 0 which generates the base-2 number system.
		for(int a = 2+p; a <= end; a++){
			fibNumbers->push_back(pow(2, a -1));
		}
	} else {
		//A fibonacci number the sum (product) of the number before
		//it and the number p+1 spots behind it.
		for(int i = 2+p; i <= end; i++){
			int num1 = fibNumbers->at(i - 1);
			int num2 = fibNumbers->at(i - 1 - p);
			if(op == 0){
				fibNumbers->push_back(num1 + num2);
			} else if (op == 1){
				fibNumbers->push_back(num1 * num2);
			}
		}
	}
	for(int j = start - 1; j < end; j++){
		result->push_back(fibNumbers->at(j));
	}
	return result;
}

Fibonacci::~Fibonacci(){
	delete fibNumbers;
}

Fibonacci::Fibonacci(int p){
	Fibonacci::p = p;
	op = 0; //default set to addition
	fibNumbers = new vector<int>();
	initList();
}

Fibonacci::Fibonacci(int p, int op){
	Fibonacci::p = p;
	fibNumbers = new vector<int>();
	if(op >= 0 && op < 2){
		Fibonacci::op = op;
	} else {
		cout << "Invalid operator used" << endl;
	}
	initList();
}

