#ifndef CHUNKER_H
#define CHUNKER_H

#define CHUNK_SIZE 3
#define DECIMAL_PLACES 2

#include <vector>
#include <string>
#include "numberSystem.h"

using namespace std;

class Chunker {
private:
    float RoundFloat(float number);
    //encoding
    vector<float> NumberToChunks(string number);
    vector< vector<int> > ChunksToBits(vector<float> chunks, NumberSystem* sys);
    float StringToFloat(string number);
    string AdjustChunk(string number);

    //decoding
    vector<float> BitsToChunks(vector< vector<int> > bitChunks, NumberSystem* sys);
    float BitsToFloat(vector<int> pattern, NumberSystem *sys);
    string ChunksToNumber(vector<float> chunks);
    string FloatToString(float f);
public:
    vector<int> GetBitRepresentation(string number, NumberSystem* sys);
    string GetNumberRepresentation(vector<int> bits, NumberSystem* sys);
    static string GetBitString(vector<int> bits);
};

#endif // CHUNKER_H
