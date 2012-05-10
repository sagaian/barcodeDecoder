/*
 * multiBase.cpp
 */

using namespace std;
#include "numberSystem.h"
#include "multiBase.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <stdarg.h>
#include <assert.h>

void MultiBase::FuseSystem(NumberSystem *sys, int op){
	vector<float> newSequence;
	vector<float> *seq = sys->getSequence();
	if(op == 0){
		for(size_t i = 0; i < sequence->size(); i++){
			for(size_t j = 0; j < seq->size(); j++){
				newSequence.push_back(sequence->at(i) + seq->at(j));
			}
		}
	} else {
		for(size_t i = 0; i < sequence->size(); i++){
			for(size_t j = 0; j < seq->size(); j++){
				newSequence.push_back(sequence->at(i) * seq->at(j));
			}
		}
	}
	*sequence = newSequence;
}

MultiBase::MultiBase(int op, int count, ...){
	va_list systems;
	va_start(systems, count);
	for(int i = 0; i < count; ++i ){
		NumberSystem *s = va_arg(systems, NumberSystem *);
		if(i == 0){
			*sequence = *s->getSequence();
		} else {
			FuseSystem(s, op);
		}
	}
	va_end(systems);
}




