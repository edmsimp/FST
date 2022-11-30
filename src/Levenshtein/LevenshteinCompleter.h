#ifndef LEVENSHTEIN_COMPLETER_H
#define LEVENSHTEIN_COMPLETER_H

#include "Levenshtein.h"

class LevenshteinCompleter{
public:
    LevenshteinCompleter(std::vector<std::string> &dictionary, std::vector<std::string> *matchedStrings, int quantityToMatch, int maxQuantityToMatch);
    void setMatchesNumber(int matchesNumber);
    void autoComplete(std::string key);

private:
    LevenshteinAutomata* automata;
    std::vector<std::string> *matchedStrings;
    int maxMatches;
    int matchesNumber;
};

#endif