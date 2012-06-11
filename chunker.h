#ifndef CHUNKER_H
#define CHUNKER_H

#define CHUNK_SIZE 2
#define DECIMAL_PLACES 2

#include <vector>
#include <string>
#include "numberSystem.h"

using namespace std;

class Chunker {
private:
    static float RoundFloat(float number);
    //encoding
    static vector<float> NumberToChunks(string number);
    static vector< vector<int> > ChunksToBits(vector<float> chunks, NumberSystem* sys);
    static float StringToFloat(string number);
    static string AdjustChunk(string number);
    //decoding
    static vector<float> BitsToChunks(vector< vector<int> > bitChunks, NumberSystem* sys);
    static float BitsToFloat(vector<int> pattern, NumberSystem *sys);
    static string ChunksToNumber(vector<float> chunks);
    static string FloatToString(float f);
public:
    static vector<int> GetBitRepresentation(string number, NumberSystem* sys);
    static string GetNumberRepresentation(vector<int> bits, NumberSystem* sys);
    static string GetBitString(vector<int> bits);
    static const size_t maxSeqValue; //pow(10,CHUNK_SIZE) -1
};

#endif // CHUNKER_H
