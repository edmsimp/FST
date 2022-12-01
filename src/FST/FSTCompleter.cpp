#include "FSTCompleter.h"

FSTCompleter::FSTCompleter(std::vector<std::string> &dictionary, std::vector<std::string> *matchedStrings, int quantityToMatch, int maxQuantityToMatch) {
    this->matchedStrings = matchedStrings;
    this->matchesNumber = quantityToMatch;
    this->maxMatches = maxQuantityToMatch;
    this->fst.loadFST(dictionary);
}

void FSTCompleter::setMatchesNumber(int matchesNumber) {
    this->matchesNumber = matchesNumber;
}

void FSTCompleter::autoComplete(std::string key) {
    this->matchedStrings->clear();
    this->fst.matchStrings(key, *this->matchedStrings, this->matchesNumber);
    for (int i = this->matchedStrings->size(); i < this->maxMatches; i++) {
        this->matchedStrings->push_back("");
    }
}