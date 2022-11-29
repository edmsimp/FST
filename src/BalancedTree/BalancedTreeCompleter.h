#ifndef BALANCED_TREE_COMPLETER
#define BALANCED_TREE_COMPLETER

#include <iostream>
#include <string>
#include <vector>
#include "RBTree.h"

class BalancedTreeCompleter {
private:
    RBTree tree;
    int maxMaches;
    std::vector<std::string> matchedStrings;

public:
    BalancedTreeCompleter(std::vector<std::string> &dictionary, std::vector<std::string> &matchedStrings, int quantityToMatch);

    void autoComplete(std::string key);
};

#endif