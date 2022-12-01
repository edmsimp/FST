#ifndef BALANCED_TREE_COMPLETER
#define BALANCED_TREE_COMPLETER

#include "RBTree.h"

class BalancedTreeCompleter {
public:
    BalancedTreeCompleter(std::vector<std::string> &dictionary, std::vector<std::string> *matchedStrings, int quantityToMatch, int maxQuantityToMatch);
    void setMatchesNumber(int matchesNumber);
    void autoComplete(std::string key);

private:
    RBTree tree;
    std::vector<std::string> *matchedStrings;
    int maxMatches;
    int matchesNumber;
};

#endif