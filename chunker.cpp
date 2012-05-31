#include <vector>
#include <string>
#include <sstream>
#include "numberSystem.h"
#include "math.h"
#include "chunker.h"

using namespace std;

//Encoder
float Chunker::StringToFloat(string number){
    float result = 0;
    float decimal = false;
    float divider = 1;
    for(int i = 0; i < (int)number.length(); i++){
        if(number.at(i) == '.'){
            decimal = true;
        }else{
            if(decimal){
                divider *= 10;
            }
            result *= 10;
            result += number.at(i) - '0';
        }
    }
    return (result/divider);
}

/*
 * We only adjust the size if we know that the chunk is smaller than CHUNK_SIZE
 */
string Chunker::AdjustChunk(string number){
    int decimal = 0;
    string adjustmentString = "";
    for(unsigned int i = 0; i < number.length(); i++){
        if(number.at(i) == '.'){
            decimal = 1;
            break;
        }
    }
    int adjustment = CHUNK_SIZE - (number.length()-decimal);
    for(int j = 0; j < adjustment; j++){
        adjustmentString += '0';
    }
    return adjustmentString.append(number);
}

vector<float> Chunker::NumberToChunks(string number){
    vector<float> chunks;
    chunks.reserve(CHUNK_SIZE+1);
    string chunk = "";
    unsigned int index;
    while(number.length() > 0){
        if(number.length() < CHUNK_SIZE){
            number = AdjustChunk(number);
        }
        index = 0;
        for(int i = 0; i < CHUNK_SIZE;  i++){
            if(number.at(number.length()-(index+1)) == '.'){
                i--;
            }
            index++;
        }
        if(number.length() > index && number.at(number.length()-(index+1))=='.'){
            index++;
        }
        chunk = number.substr(number.length()-index);
        number = number.substr(0,number.length()-index);
        chunks.insert(chunks.begin(),StringToFloat(chunk));
    }
    return chunks;
}

vector< vector<int> > Chunker::ChunksToBits(vector<float> chunks, NumberSystem* sys){
    vector< vector<int> > bitChunks;
    bitChunks.reserve(chunks.size());
    for(unsigned int i = 0; i < chunks.size(); i++){
        vector<int> bitChunk;
        sys->getGreedyRepresentation(chunks.at(i), &bitChunk);
        bitChunks.push_back(bitChunk);
    }
    return bitChunks;
}
vector<int> Chunker::GetBitRepresentation(string number, NumberSystem *sys){
    vector<float> chunks = NumberToChunks(number);
    vector< vector<int> > bitChunks = ChunksToBits(chunks, sys);
    vector<int> bitRepresentation;
    bitRepresentation.reserve(bitChunks.size()*(bitChunks.at(0).size()));
    for(unsigned int i = 0; i < bitChunks.size(); i++){
        bitRepresentation.insert(bitRepresentation.end(), bitChunks.at(i).begin(), bitChunks.at(i).end());
    }
    return bitRepresentation;
}

string Chunker::GetBitString(vector<int> bits){
    string result = ""; //beginning of barcode
    for(unsigned int i = 0; i < bits.size(); i++){
        result += '0' + bits.at(i);
    }
    //result.append("01");
    return result;
}


//Decoder

float Chunker::RoundFloat(float number){
    float rounding = pow(10,DECIMAL_PLACES);
    number *= rounding;
    int integer = (int)number;
    if((number - (float)integer) >= .5){
        integer +=1;
    }
    return (float)integer/rounding;
}

string Chunker::FloatToString(float number){
    stringstream ss;
    ss << number;
    return ss.str();
}

float Chunker::BitsToFloat(vector<int> pattern, NumberSystem *sys){
    vector<float> *seq = sys->getSequence();
    float f = 0;
    for(unsigned int i = 0; i < pattern.size(); i++){
        if(pattern.at(i)){
           f += seq->at(i);
        }
    }
    return f;
}

vector<float> Chunker::BitsToChunks(vector<vector<int> > bitChunks, NumberSystem *sys){
    vector<float> chunks;
    for(unsigned int i = 0; i < bitChunks.size(); i++){
        chunks.push_back(BitsToFloat(bitChunks.at(i), sys));
    }
    return chunks;
}

string Chunker::ChunksToNumber(vector<float> chunks){
    string result = "";
    string chunk;
    for(unsigned int i = 0; i < chunks.size(); i++){
        chunk = FloatToString(RoundFloat(chunks.at(i)));
        if(i != 0){
            chunk = AdjustChunk(chunk);
        }
        result.append(chunk);
    }
    return result;
}

string Chunker::GetNumberRepresentation(vector<int> bits, NumberSystem* sys){
    vector<float>* sequence = sys->getSequence();
    unsigned int chunkSize = sequence->size();
    vector< vector<int> > chunks;
    for(int i = 1; i <= (bits.size()/chunkSize); i ++){
        vector<int> chunk;
        chunk.insert(chunk.begin(), bits.begin() + ((i-1)*chunkSize), bits.begin() + (i*chunkSize));
        chunks.push_back(chunk);
    }
    return ChunksToNumber(BitsToChunks(chunks, sys));
}


