#include "LevenshteinCompleter.h"

LevenshteinCompleter::LevenshteinCompleter(std::vector<std::string> &dictionary, std::vector<std::string> *matchStrings, 
                                           int quantityToMatch, int maxQuantityToMatch){
    automata = new LevenshteinAutomata(dictionary);
    matchedStrings = matchStrings;
    matchesNumber = quantityToMatch;
    maxMatches = maxQuantityToMatch;
}

void LevenshteinCompleter::setMatchesNumber(int matchNumber) {
    matchesNumber = matchNumber;
}

void LevenshteinCompleter::autoComplete(std::string key) {
    matchedStrings->clear();
    automata->getWords(key, matchedStrings, matchesNumber);
}