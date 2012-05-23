#ifndef ENCODER_H
#define ENCODER_H

#include <vector>
#include <string>

using namespace std;

class Encoder {
private:
    string getDimensions(size_t ncols, size_t nrows);
public:
    void EncodeBinary(vector<int> *binary, string path);
    string VectorToString(vector<int> *data);
};


#endif // ENCODER_H
