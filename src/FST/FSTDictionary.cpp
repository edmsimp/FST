#include "FSTDictionary.h"

state FSTDictionary::findState (state s) {
    for(std::vector<state>::iterator it = this->states.begin(); it < this->states.end(); it++)
        if (*it == s) return *it;
    return nullptr;
}

void FSTDictionary::addState (state s) {
    this->states.emplace_back(s);
}

std::vector<state> FSTDictionary::getStates () {
    return this->states;
}

dictionary FSTDictionary::newDictionary () {
    return std::make_shared<FSTDictionary>();
}

state FSTDictionary::member(dictionary d, state s) {
    return d->findState(s);
}

void FSTDictionary::insert(dictionary d, state s) {
    d->addState(s);
}