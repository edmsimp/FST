#include "FSTState.h"

bool FSTState::getIsFinal() {
    return this->isFinal;
}

void FSTState::setIsFinal(bool f) {
    this->isFinal = f;
}

state FSTState::getTransition(char c) {
    return this->transitions.at(c);
}

void FSTState::setTransition(char c, state s) {
    this->transitions.insert({c, s});
}

void FSTState::clearTransitions() {
    this->transitions.clear();
}

std::set<std::string> FSTState::getStrings() {
    return this->strings;
}

void FSTState::setStrings(std::set<std::string> s) {
    this->strings = s;
}

std::string FSTState::getOutput(char c) {
    return this->outputs.at(c);;
}

void FSTState::setOutput(char c, std::string s) {
    this->outputs.insert({c, s});
}

std::map<char, std::string> FSTState::getOutputsMap() {
    return this->outputs;
}

std::map<char, state> FSTState::getTransitionsMap() {
    return this->transitions;
}

/*************************************************************************************/

state FSTState::newState() {
    state s = std::make_shared<FSTState>();
    for(char c = FIRST_CHAR; c <= LAST_CHAR; c++)
        s->setTransition(c, nullptr);
    for(char c = FIRST_CHAR; c <= LAST_CHAR; c++)
        s->setOutput(c, "");
    s->getStrings().clear();
    return s;
}

state FSTState::getTransition(state s, char c) {
    return s->getTransition(c);
}

void FSTState::setTransition(state s, char c, state ns) {
    s->setTransition(c, ns);
}

std::set<std::string> FSTState::stateOutput(state s) {
    return s->getStrings();
}

void FSTState::setStateOutput(state s, std::set<std::string> so) {
    s->setStrings(so);
}

std::string FSTState::output(state s, char c) {
    return s->getOutput(c);
}

void FSTState::setOutput(state s, char c, std::string o) {
    s->setOutput(c, o);
}

/*************************************************************************************/

state FSTState::copyState(state s) {
    state ns = newState();
    *ns = *s;
    return ns;
}

void FSTState::clearState(state s) {
    for(char c = FIRST_CHAR; c <= LAST_CHAR; c++)
        s->setTransition(c, nullptr);
    for(char c = FIRST_CHAR; c <= LAST_CHAR; c++)
        s->setOutput(c, "");
    s->getStrings().clear();
    s->setIsFinal(false);
}

bool FSTState::compareState(state s1, state s2) {
    return s1 == s2;
}
