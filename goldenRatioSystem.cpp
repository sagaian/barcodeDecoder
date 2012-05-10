/*
 * goldenRatioSystem.cpp
 */

using namespace std;
#include "numberSystem.h"
#include "goldenRatioSystem.h"
#include <vector>
#include <math.h>

void GoldenRatio::generateSequence(int start, int end, float ratio){
	for(int i = start; i <= end; i++){
		sequence->push_back((float)pow(ratio, i));
	}
}

void GoldenRatio::generateSequence(int maxValue, float ratio){
	int i = log(EPSILON)/log(ratio);
	while(true){
		float nextTerm = (float)pow(ratio, i);
		if(nextTerm > maxValue) break;
		sequence->push_back(nextTerm);
		i++;
	}
}

GoldenRatio::GoldenRatio(int start, int end, float ratio){
	generateSequence(start, end, ratio);
}

GoldenRatio::GoldenRatio(int maxValue, float ratio){
	generateSequence(maxValue, ratio);
}

