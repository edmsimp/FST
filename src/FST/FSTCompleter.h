#ifndef FST_COMPLETER
#define FST_COMPLETER

#include <iostream>
#include <string>
#include <vector>
#include "FST.h"

class FSTCompleter {
private:
    FST fst;
    int maxMatches;
    int matchesNumber;
    std::vector<std::string> *matchedStrings;

public:
    FSTCompleter(std::vector<std::string> &dictionary, std::vector<std::string> *matchedStrings, int quantityToMatch, int maxQuantityToMatch);

    void setMatchesNumber(int matchesNumber);

    void autoComplete(std::string key);
};

#endif