#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <vector>
#include <map>

#define EDGE_PENALTY 4
#define MAX_RUN 3
#define EFFICIENCY_FACTOR .8

using namespace std;

class Compressor {
private:
    static const size_t seqLen;

    /* bit strings */
    static const vector< vector<int> > bestSequences;
    static int ScoreBitSequence(vector<int> *bits);
    static bool isUsableSequence(vector<int> *bits);
    static void GetBestSequences(vector<vector<int> > *bitsequences, vector<int> *scores, vector<int> sequence);
    static vector<vector<int> > GetBestSequencesWrapper();

    /* term order*/
    static vector< vector<int> > getTermSequences(NumberSystem* sys);
    static map<int,int> getTermCounts(vector< vector<int> > *bitSequences);
    static vector<int> getTermOrder(map<int,int> termCounts);
    static vector<int> GetOrderedTerms(NumberSystem *sys);

    /* encoding map */
    static map<int, vector<int> > getEncodingMapCompression(vector<int> *terms);
    static map<vector<int>,int > getEncodingMapExpansion(vector<int> *terms);

public:
    //Standard
    static vector<int> CompressBitSequence(vector<int> *bits, NumberSystem* sys);
    static vector<int> ExpandBitSequence(vector<int> *bits, NumberSystem* sys);

    //Used for Testing (Multiple runs with the same number systems.
    static map<int, vector<int> > getEncodingMapCompression(NumberSystem* sys);
    static map<vector<int>,int > getEncodingMapExpansion(NumberSystem* sys);

    /* expanding/compressing bits */
    static vector<int> GetCompressedBits(vector<int> *bits, NumberSystem *sys,const map<int,vector<int> > *encodings);
    static vector<int> GetExpandedBits(vector<int> *bits, NumberSystem *sys, const map<vector<int>,int> *encodings);

};

#endif // COMPRESSOR_H
