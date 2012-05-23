#ifndef ENHANCER_H
#define ENHANCER_H
#include <Magick++.h>
#include "numberSystem.h"
#include "goldenRatioSystem.h"
using namespace std;
using namespace Magick;

#define MAX_VALUE 256.0
#define MU 500.0
#define LAMDA -300.0
#define BETA 3.0

class Enhancer{
private:
    string getDimensions(size_t ncols, size_t nrows); // concats dimensions as string
    float PlipGt(float pixel); // PLIP scaling
    float PlipPhi(float pixel); // PLIP phi transform
    float PlipInvPhi(float pixel); // PLIP inverse phi transform
    float PlipMulp(float pixel1, float pixel2); // PLIP multiplication
    // split pixel value into lower and upper half (as determined by threshold), returns lower
    float SplitPixel(float pixel, NumberSystem *s, size_t nTerms, size_t threshold);
public:
    void EnhanceImage(Image image, NumberSystem *sys);
};

#endif // ENHANCER_H
