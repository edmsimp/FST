#include "GenericCompleter.h"

GenericCompleter::GenericCompleter(std::vector<std::string> &dictionary, std::vector<std::string> &matchStrings, int quantityToMatch, int maxQuantityToMatch){
    completer1 = new FSTCompleter(dictionary, &matchStrings, quantityToMatch, maxQuantityToMatch);
    completer2 = new BalancedTreeCompleter(dictionary, &matchStrings, quantityToMatch, maxQuantityToMatch);
    completer3 = new LevenshteinCompleter(dictionary, &matchStrings, quantityToMatch, maxQuantityToMatch);
}

void GenericCompleter::selectCompleter(int completerId){
    activeCompleter = completerId;
}

void GenericCompleter::setMatchesNumber(int matchesNumber){
    completer1->setMatchesNumber(matchesNumber);
    completer2->setMatchesNumber(matchesNumber);
    completer3->setMatchesNumber(matchesNumber);
}

void GenericCompleter::autoComplete(std::string key){
    switch(activeCompleter){
        case 1: completer1->autoComplete(key); break;
        case 2: completer2->autoComplete(key); break;
        case 3: completer3->autoComplete(key); break;
        default: break;
    }
}