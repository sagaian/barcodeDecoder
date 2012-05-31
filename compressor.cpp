#include <vector>
#include <string>
#include <map>
#include <math.h>
#include "chunker.h"
#include "compressor.h"
#include "numberSystem.h"
#include <assert.h>

using namespace std;

/*
 * This is the scoring function that dictates how good a bit string is.
 * EDGE_PENALTY is the additional penalty imposed for having a bit on
 * the start or end.
 * Lower score is better.
 */
int Compressor::ScoreBitSequence(vector<int> bits){
    /*
     * Here is the scoring method we used before.
     * Each 1 is worth the current run length so
     * 111 is (1+2+3+EDGE+PENALTY*2) = 6 + 2*EDGE_PENALTY
     */
    int score = 0;
    int currentRun = 0;
    for(unsigned int i = 0 ; i < bits.size(); i++){
        if(bits.at(i) == 1){
            currentRun++;
            score += currentRun;
        }else{
            currentRun = 0;
        }
    }
    if(bits.at(0) == 1){
        score += EDGE_PENALTY;
    }
    if(bits.at(bits.size()-1) == 1){
        score += EDGE_PENALTY;
    }
    return score;
}

/*
 * Determines whether a string should be used or not.
 * Current implementation makes decision based on whether or
 * not the string has a run of 1s that exceeds MAX_RUN.
 */
bool Compressor::isUsableSequence(vector<int> bits){
    int currentRun = 0;
    for(unsigned int i = 0; i < bits.size(); i++){
        if(bits.at(i) == 1){
            currentRun++;
            if(currentRun > MAX_RUN){
                return false;
            }
        }else{
            currentRun = 0;
        }
    }
    return true;
}

//returns what it considered to be the best bit sequences of a specified size and puts them in bit sequences vector.
//This is a recursive function, sequence is the sequence generated so far, when it hits size it is
//inserted into bitSequences where it fits according to its score.
void Compressor::GetBestSequences(vector < vector<int> > *bitsequences, vector<int> *scores ,vector<int> sequence, size_t size){
    if(sequence.size() < size){
        sequence.push_back(0);
        GetBestSequences(bitsequences, scores, sequence, size);
        sequence.pop_back();
        sequence.push_back(1);
        GetBestSequences(bitsequences, scores, sequence, size);
    } else {
        //only add if it is good
        if(isUsableSequence(sequence)){
            int score = ScoreBitSequence(sequence);
            //check if this is first sequence
            if(scores->empty()){
                bitsequences->push_back(sequence);
                scores->push_back(score);
                return;
            }
            //if it is not first sequence compare its score against those already stored
            //Current bitsequences are already sorted.
            for(size_t i = 0; i < scores->size(); i++){
                if(score < scores->at(i)){
                    scores->insert(scores->begin() + i, score);
                    bitsequences->insert(bitsequences->begin() + i, sequence);
                    return;
                    //we reached the end, this is the worst sequence
                }else if(i == scores->size() -1){
                    scores->push_back(score);
                    bitsequences->push_back(sequence);
                    return;
                }
            }
        }
    }
}

vector< vector<int> > Compressor::getTermSequences(NumberSystem *sys){
    int max = pow(10,CHUNK_SIZE);
    vector< vector<int> > bitSequences;
    for(int i = 0; i < max; i++){
        vector<int> sequence;
        sys->getGreedyRepresentation(i,&sequence);
        bitSequences.push_back(sequence);
    }
    return bitSequences;
}

/*
 * Returns a map where the key is a term index and its value is the number of times it appears
 * in the bitSequences passed in.
 */
map<int,int> Compressor::getTermCounts(vector<vector<int> > bitSequences){
    map<int,int> termCounts;
    for(unsigned int i = 0; i < bitSequences.size(); i++){
        vector<int> currentSequence = bitSequences.at(i);
        for(unsigned int j = 0; j < currentSequence.size(); j++){
            if(currentSequence.at(j) == 1)termCounts[j]++;
        }
    }
    return termCounts;
}

/*
 * Returns a vector with the terms ordered from most likely to least likely.
 */
vector<int> Compressor::getTermOrder(map<int,int> termCounts){
    vector<int> orderedTerms;
    orderedTerms.reserve(termCounts.size());
    int currentTerm = 0;
    orderedTerms.push_back(termCounts.begin()->first);
    //We itereate through the keys in the map, each time inserting each
    //key where it belongs in the orederedTerms vector.
    map<int,int>::iterator itr;
    for(itr = ++termCounts.begin(); itr != termCounts.end(); itr++){
        currentTerm = itr->first;
        for(unsigned int i = 0; i < orderedTerms.size(); i++){
            if(termCounts[currentTerm] > termCounts[orderedTerms.at(i)]){
                orderedTerms.insert(orderedTerms.begin()+i,currentTerm);
                break;
            }
            if(i == orderedTerms.size() - 1){
                orderedTerms.push_back(currentTerm);
                break;
            }
        }
    }
    return orderedTerms;
}

/*
 * Returns a mapping from term to bit sequences. The most common terms gets mapped to the most
 * desired bit sequences. These should already be ordered in terms and bitSequences.
 */
map<int,vector<int> > Compressor::getEncodingMapCompression(vector<int> terms, vector<vector<int> > bitSequences){
    assert(terms.size() <= bitSequences.size());
    map<int,vector<int> > encodings;
    for(unsigned int i = 0; i < terms.size(); i++){
        encodings[terms.at(i)] = bitSequences.at(i);
    }
    return encodings;
}

map<vector<int>,int> Compressor::getEncodingMapExpansion(vector<int> terms, vector<vector<int> > bitSequences){
    map<vector<int>, int > encodings;
    for(unsigned int i = 0; i < terms.size(); i++){
        encodings[bitSequences.at(i)] = terms.at(i);
    }
    return encodings;
}


/*
 * Public function that decompresses bit sequence.
 * Named this way to clearly distinguish compression and
 * decompression.
 */
vector<int> Compressor::ExpandBitSequence(vector<int> bits, NumberSystem* sys){
    int len = ceil(log((pow(10, CHUNK_SIZE)-1))/log(2));
    //get ordered terms
    vector< vector<int> > termSequences = getTermSequences(sys);
    map<int, int> termCounts = getTermCounts(termSequences);
    vector<int> orderTerms = getTermOrder(termCounts);

    //get best sequences
    vector<vector<int> >bestSequences;
    vector<int> sequence, scores;
    GetBestSequences(&bestSequences, &scores, sequence, len);
    map<vector<int>,int> encodings = getEncodingMapExpansion(orderTerms, bestSequences);

    vector<int> indexes(sys->getSequence()->size(), 0);
    size_t bitsWithoutPadding  = (bits.size() / (len + 1)) * (len + 1);
    int offset = 0;
    int extraModules = 0;
    for(size_t i = 0; i < bitsWithoutPadding ; i+=len+1){
        vector<int> seq;
        seq.insert(seq.begin(), bits.begin() + i, bits.begin() + i+ len);
        int index = encodings.find(seq)->second;
        if(i!= 0 && (i-extraModules)%len == 0 && bits.at(i-1)== 0){
            offset += sys->getSequence()->size();
            vector<int> newChunkIndexes(sys->getSequence()->size(), 0);
            indexes.insert(indexes.end(), newChunkIndexes.begin(), newChunkIndexes.end());
        }
        indexes[index + offset] = 1;
        extraModules++;
    }
    return indexes;
}


/*
 * Public function that compresses a bit sequence.
 */
vector<int> Compressor::CompressBitSequence(vector<int> bits, NumberSystem* sys){
    int len = ceil(log((pow(10, CHUNK_SIZE)-1))/log(2));
    vector<vector<int> > termSequences = getTermSequences(sys);
    map<int, int> termCounts = getTermCounts(termSequences);
    vector<int> orderTerms = getTermOrder(termCounts);
    vector<vector<int> > bestSequences;
    vector<int> v, scores;
    GetBestSequences(&bestSequences, &scores, v, len);

    map<int,vector<int> > encodings = getEncodingMapCompression(orderTerms, bestSequences);
    vector<int> compressedBits;

    size_t prevChunk = 0;
    //if i am in the chunk, pad with 1; if i am outside chunk, pad with 0
    for(size_t i = 0; i < bits.size(); i++){
        if(bits.at(i)){
            if(i != 0){
                size_t currChunk = i / sys->getSequence()->size();
                if(currChunk == prevChunk) {
                    compressedBits.push_back(1);
                } else {
                    compressedBits.push_back(0);
                    prevChunk++;
                }
            }
            vector<int> compressedTerm = encodings.find(i % sys->getSequence()->size())->second;
            for(size_t j = 0; j < compressedTerm.size(); j++){
                compressedBits.push_back(compressedTerm.at(j));
            }

        }
    }
    compressedBits.push_back(0);
    return compressedBits;
}
