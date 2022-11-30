#include "BalancedTreeCompleter.h"

BalancedTreeCompleter::BalancedTreeCompleter(std::vector<std::string> &dictionary, std::vector<std::string> &matchedStrings, int quantityToMatch, int maxQuantityToMatch) {
    this->matchedStrings = &matchedStrings;
    this->matchesNumber = quantityToMatch;
    this->maxMatches = maxQuantityToMatch;
    this->tree.loadTree(dictionary);
}

void BalancedTreeCompleter::setMatchesNumber(int matchesNumber) {
    this->matchesNumber = matchesNumber;
}

void BalancedTreeCompleter::autoComplete(std::string key) {
    NodePtr treeRoot = this->tree.getRoot();
    this->matchedStrings->clear();
    this->tree.matchStrings(treeRoot, key, *this->matchedStrings, this->matchesNumber);
    for (int i = this->matchedStrings->size(); i < this->maxMatches; i++) {
        this->matchedStrings->push_back("");
    }
}