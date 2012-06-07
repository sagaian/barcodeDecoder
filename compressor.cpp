#include <vector>
#include <string>
#include <map>
#include <math.h>
#include "chunker.h"
#include "compressor.h"
#include "numberSystem.h"
#include <assert.h>

using namespace std;

const size_t Compressor::seqLen = ceil(log((pow(10, CHUNK_SIZE)-1))/log(2)) + 1; // +1 in case too many bad sequences leave
                                                                                 // too little sequences for too many terms

const vector< vector<int> > Compressor::bestSequences = GetBestSequencesWrapper();

/* ================= bit strings ========================*/

/*
 * This is the scoring function that dictates how good a bit string is.
 * EDGE_PENALTY is the additional penalty imposed for having a bit on
 * the start or end.
 * Lower score is better.
 */
int Compressor::ScoreBitSequence(vector<int> *bits){
    /*
     * Here is the scoring method we used before.
     * Each 1 is worth the current run length so
     * 111 is (1+2+3+EDGE+PENALTY*2) = 6 + 2*EDGE_PENALTY
     */
    int score = 0;
    int currentRun = 0;
    for(unsigned int i = 0 ; i < bits->size(); i++){
        if(bits->at(i) == 1){
            currentRun++;
            score += currentRun;
        }else{
            currentRun = 0;
        }
    }
    if(bits->at(0) == 1){
        score += EDGE_PENALTY;
    }
    if(bits->at(bits->size()-1) == 1){
        score += EDGE_PENALTY;
    }
    return score;
}

/*
 * Determines whether a string should be used or not.
 * Current implementation makes decision based on whether or
 * not the string has a run of 1s that exceeds MAX_RUN.
 * We reserve the sequence of 0's to pad the barcode and
 * don't allow it to be a usable sequence
 */
bool Compressor::isUsableSequence(vector<int> *bits){
    size_t currentRunOnes = 0;
    size_t currentRunZeros = 0;
    size_t len = bits->size();
    for(size_t i = 0; i < len; i++){
        if(bits->at(i) == 1){
            currentRunZeros = 0;
            currentRunOnes++;
            if(currentRunOnes > MAX_RUN){
                return false;
            }
        }else{
            currentRunOnes = 0;
            currentRunZeros++;
        }
    }
    if(currentRunZeros == len) return false; //disallow the use of sequence of zeros as usable sequence
    return true;
}

//returns what it considered to be the best bit sequences of a specified size and puts them in bit sequences vector.
//This is a recursive function, sequence is the sequence generated so far, when it hits size it is
//inserted into bitSequences where it fits according to its score.
void Compressor::GetBestSequences(vector < vector<int> > *bitsequences, vector<int> *scores ,vector<int> sequence){
    if(sequence.size() < seqLen){
        sequence.push_back(0);
        GetBestSequences(bitsequences, scores, sequence);
        sequence.pop_back();
        sequence.push_back(1);
        GetBestSequences(bitsequences, scores, sequence);
    } else {
        //only add if it is good
        if(isUsableSequence(&sequence)){
            int score = ScoreBitSequence(&sequence);
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

vector<vector<int> > Compressor::GetBestSequencesWrapper(){
    vector<vector<int> >bestSequences;
    vector<int> sequence, scores;
    GetBestSequences(&bestSequences, &scores, sequence);
    return bestSequences;
}

/* ================= term order ========================*/

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
map<int,int> Compressor::getTermCounts(vector<vector<int> > *bitSequences){
    map<int,int> termCounts;
    for(unsigned int i = 0; i < bitSequences->size(); i++){
        vector<int> currentSequence = bitSequences->at(i);
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
    size_t numTerms = termCounts.size();
    orderedTerms.reserve(numTerms);
    int currentTerm = 0;
    orderedTerms.push_back(termCounts.begin()->first);
    //We itereate through the keys in the map, each time inserting each
    //key where it belongs in the orederedTerms vector.
    map<int,int>::iterator itr;
    for(itr = ++termCounts.begin(); itr != termCounts.end(); itr++){
        currentTerm = itr->first;
        for(unsigned int i = 0; i < numTerms; i++){
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

vector<int> Compressor::GetOrderedTerms(NumberSystem* sys){
    vector< vector<int> > termSequences = getTermSequences(sys);
    map<int, int> termCounts = getTermCounts(&termSequences);
    return getTermOrder(termCounts);
}

/* =================  encoding/ decoding maps  ========================*/

/*
 * Returns a mapping from term to bit sequences. The most common terms gets mapped to the most
 * desired bit sequences. These should already be ordered in terms and bitSequences.
 */
map<int,vector<int> > Compressor::getEncodingMapCompression(vector<int> *terms){
    //assert(terms->size() <= bestSequences.size()); //important here but addressed with seqLen+1
    map<int,vector<int> > encodings;
    for(unsigned int i = 0; i < terms->size(); i++){
        encodings[terms->at(i)] = bestSequences.at(i);
    }
    return encodings;
}

map<vector<int>,int> Compressor::getEncodingMapExpansion(vector<int> *terms){
    map<vector<int>, int > encodings;
    for(unsigned int i = 0; i < terms->size(); i++){
        encodings[bestSequences.at(i)] = terms->at(i);
    }
    return encodings;
}

/* ================= expanding/compressing bits ========================*/

vector<int> Compressor::GetExpandedBits(vector<int> *bits, NumberSystem *sys, const map<vector<int>,int> *encodings){
    size_t expandedBitsSize = sys->getSequence()->size();
    vector<int> expandedBits(expandedBitsSize, 0);
    size_t bitsWithoutPadding  = (bits->size() / (seqLen + 1)) * (seqLen + 1);
    int offset = 0;
    int extraModules = 0;
    map<vector<int>,int>::const_iterator it;
    for(size_t i = 0; i < bitsWithoutPadding ; i+=seqLen+1){
        vector<int> seq;
        seq.insert(seq.begin(), bits->begin() + i, bits->begin() + i+ seqLen);
        it = encodings->find(seq);
        if(it == encodings->end()) break; /* Pattern not found or ending reached */
        int index = it->second;
        if(i!= 0 && (i-extraModules)%seqLen == 0 && bits->at(i-1)== 0){
            offset += sys->getSequence()->size();
            vector<int> newChunk(sys->getSequence()->size(), 0);
            expandedBits.insert(expandedBits.end(), newChunk.begin(), newChunk.end());
        }
        expandedBits[index + offset] = 1;
        extraModules++;
    }
    return expandedBits;
}

vector<int> Compressor::GetCompressedBits(vector<int> *bits, NumberSystem *sys, const map<int,vector<int> > *encodings){
    vector<int> compressedBits;
    size_t prevChunk = 0;
    //if i am in the chunk, pad with 1; if i am outside chunk, pad with 0
    for(size_t i = 0; i < bits->size(); i++){
        if(bits->at(i)){
            if(i != 0){
                size_t currChunk = i / sys->getSequence()->size();
                if(!compressedBits.empty()){
                    if(currChunk == prevChunk) {
                        compressedBits.push_back(1);
                    } else {
                        compressedBits.push_back(0);
                        prevChunk++;
                    }
                }
            }
            vector<int> compressedTerm = encodings->find(i % sys->getSequence()->size())->second;
            for(size_t j = 0; j < compressedTerm.size(); j++){
                compressedBits.push_back(compressedTerm.at(j));
            }

        }
    }
    compressedBits.push_back(0);
    return compressedBits;
}

/* ================= public methods ========================*/

/*
 * Public function that decompresses bit sequence.
 * Named this way to clearly distinguish compression and
 * decompression.
 */
vector<int> Compressor::ExpandBitSequence(vector<int> *bits, NumberSystem* sys){
    vector<int> orderTerms = GetOrderedTerms(sys);
    map<vector<int>,int> encodings = getEncodingMapExpansion(&orderTerms);
    return GetExpandedBits(bits, sys, &encodings);
}

/*
 * Public function that compresses a bit sequence.
 */
vector<int> Compressor::CompressBitSequence(vector<int> *bits, NumberSystem* sys){
    vector<int> orderTerms = GetOrderedTerms(sys);
    map<int,vector<int> > encodings = getEncodingMapCompression(&orderTerms);
    return GetCompressedBits(bits, sys, &encodings);
}

map<int, vector<int> > Compressor::getEncodingMapCompression(NumberSystem* sys){
    vector<int> orderTerms = GetOrderedTerms(sys);
    return getEncodingMapCompression(&orderTerms);
}

map<vector<int>,int > Compressor::getEncodingMapExpansion(NumberSystem* sys){
    vector<int> orderTerms = GetOrderedTerms(sys);
    return getEncodingMapExpansion(&orderTerms);
}
