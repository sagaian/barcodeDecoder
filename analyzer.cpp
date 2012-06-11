#include "analyzer.h"

vector<NumberSystem> Analyzer::systems = generateSystemVector();

float Analyzer::getAverageLength(int min, int max, NumberSystem *sys){
    string current = "";
    int total = 0;
    vector<int> bits;
    const map<int,vector<int> > compression = Compressor::getEncodingMapCompression(sys);
    for(int i = min; i < max; i++){
        current = AlphaConverter::integerToString(i);
        bits = Chunker::GetBitRepresentation(current,sys);
        bits = Compressor::GetCompressedBits(&bits,sys,&compression);
        total += bits.size();
    }
    return total/(max-min+1);
}

vector<NumberSystem> Analyzer::generateSystemVector(){
    vector<NumberSystem> systemsVector;
    vector<NumberSystem> sys;
    //int min = pow(10,DIGITS);
    int max = pow(10,DIGITS+1) - 1;
    for(int i = P_MIN1; i <= P_MAX1; i++){
        sys.push_back(Fibonacci(i,max,OP_1));
        for(int j = P_MIN2; j <= P_MAX2; j++){
            sys.push_back(Fibonacci(j,max,OP_2));
            systemsVector.push_back(MultiBase(OP_MULTI,&sys));
            sys.pop_back();
        }
        sys.pop_back();
    }
    return systemsVector;
}

string Analyzer::getTestResuls(){
    string results = "";
    NumberSystem* best;
    float bestAvg = 1000000;
    int min = pow(10,DIGITS-1);
    int max = pow(10,DIGITS) - 1;
    float avgLength = 0;
    NumberSystem* currSystem;
    results.append("MIN:");
    results.append(AlphaConverter::integerToString(min));
    results.append(" MAX:");
    results.append(AlphaConverter::integerToString(max));
    results += '\n';
    for(unsigned int i = 0; i < systems.size(); i++){
        currSystem = &(systems.at(i));
        avgLength = getAverageLength(min,max,currSystem);
        results.append(currSystem->getDescription());
        results.append(" avgBitsPerDigit = ");
        avgLength /= (float)DIGITS;
        results.append(AlphaConverter::floatToString(avgLength));
        results += '\n';

        if(avgLength < bestAvg){
            bestAvg = avgLength;
            best = currSystem;
        }
    }
    results.append("Best System: ");
    results.append(best->getDescription());
    results.append(" avgBitsPerDigit = ");
    results.append(AlphaConverter::floatToString(bestAvg));
    return results;
}

