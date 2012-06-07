/*#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include "numberSystem.h"
#include "chunker.h"
#include "alphaConverter.h"
#include "compressor.h"
#include "math.h"
#include "multiBase.h"
#include "fibonacciSystem.h"

#define DIGITS 2
#define P_MIN1 1
#define P_MAX1 10
#define P_MIN2 1
#define P_MAX2 1
#define OP_MULTI 0
#define OP_1 0
#define OP_2 0

using namespace std;

class Analyzer {
private:
    static vector<NumberSystem> systems;
    static vector<NumberSystem> generateSystemVector();
public:
    static float getAverageLength(int min, int max, NumberSystem* sys);
    static string getTestResuls();
};
#endif // ANALYZER_H
*/
