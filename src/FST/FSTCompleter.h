#ifndef FST_COMPLETER
#define FST_COMPLETER

#include "FST.h"

class FSTCompleter {
public:
    FSTCompleter(std::vector<std::string> &dictionary, std::vector<std::string> *matchedStrings, int quantityToMatch, int maxQuantityToMatch);
    void setMatchesNumber(int matchesNumber);
    void autoComplete(std::string key);

private:
    FST fst;
    std::vector<std::string> *matchedStrings;
    int maxMatches;
    int matchesNumber;
};

#endif
