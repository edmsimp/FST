#ifndef FST_H
#define FST_H

#include "FSTDictionary.h"
#include "FSTState.h"

class FST{
public:
    FST();
    ~FST();

    std::string longestCommonPrefix (std::string arr[], int n);
    std::string leftDivision (std::string s1, std::string s2);

    state findMinimized(state s);
    void printFST(state s);

    dictionary minimalTransducerStatesDictionary;
private:
};

#endif