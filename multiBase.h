/*
 * multiBase.h
 */

using namespace std;
#ifndef MULTIBASE_H_
#define MULTIBASE_H_

#include "numberSystem.h"
#include <stdarg.h>
#include <vector>

class MultiBase : public NumberSystem {
private:
	void FuseSystem(NumberSystem *sys, int op);
public:
        MultiBase(int op, vector<NumberSystem>* systems);
#endif /* MULTIBASE_H_ */
};
