#include "Completers.h"

Completers::Completers (std::vector<std::string> &dictionary, std::vector<std::string> &matchStrings, int quantityToMatch, int maxQuantityToMatch) {
    // TODO: change completers 2 and 3
    this->completer1 = new BalancedTreeCompleter(dictionary, matchStrings, quantityToMatch, maxQuantityToMatch);
    this->completer2 = new BalancedTreeCompleter(dictionary, matchStrings, quantityToMatch, maxQuantityToMatch);
    this->completer3 = new BalancedTreeCompleter(dictionary, matchStrings, quantityToMatch, maxQuantityToMatch);
}

BalancedTreeCompleter * Completers::selectCompleter(int completerId) {
    if (completerId == 0) {
        return this->completer1;
    }
    else if (completerId == 1) {
        return this->completer2;
    }
    else {
        return this->completer3;
    }
}
