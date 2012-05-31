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
    /* bit strings */
    int ScoreBitSequence(vector<int> bits);
    bool isUsableSequence(vector<int> bits);
    void GetBestSequences(vector<vector<int> > *bitsequences, vector<int> *scores, vector<int> sequence, size_t size);

    /* term order*/
    vector< vector<int> > getTermSequences(NumberSystem* sys);
    map<int,int> getTermCounts(vector< vector<int> > bitSequences);
    vector<int> getTermOrder(map<int,int> termCounts);

    /* encoding map */
    map<int, vector<int> > getEncodingMapCompression(vector<int> terms, vector< vector<int> > bitSequences);
    map<vector<int>,int > getEncodingMapExpansion(vector<int> terms, vector< vector<int> > bitSequences);
public:
    vector<int> CompressBitSequence(vector<int> bits, NumberSystem* sys);
    vector<int> ExpandBitSequence(vector<int> bits, NumberSystem* sys);
};

#endif // COMPRESSOR_H
