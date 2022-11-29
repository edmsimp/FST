#include "BalancedTreeCompleter.h"

BalancedTreeCompleter::BalancedTreeCompleter(std::vector<std::string> &dictionary, std::vector<std::string> &matchedStrings, int quantityToMatch) {
    this->matchedStrings = matchedStrings;
    this->maxMaches = quantityToMatch;
    this->tree.loadTree(dictionary);
}

void BalancedTreeCompleter::autoComplete(std::string key) {
    NodePtr treeRoot = this->tree.getRoot();
    this->tree.matchStrings(treeRoot, key, this->matchedStrings, this->maxMaches);
}