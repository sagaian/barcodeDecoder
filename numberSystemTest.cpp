using namespace std;
#include "numberSystem.h"
#include "fibonacciSystem.h"
#include <iostream>
#include <vector>

static void PrintSequence(vector<int> *seq){
	for(size_t i = 0; i < seq->size(); i++){
		cout << seq->at(i) << ", " ;
	}
}

int main(int argc,char **argv)
{
	Fibonacci f(1, 0);
	vector<int> *seq = f.generateSequence(1, 10);
	PrintSequence(seq);
	delete seq;
	return 0;
}
