//
// Created by edusi on 29/11/2022.
//

#include "state.h"

state::state() {
    this->isFinal = false;
    this->transitions.clear();
}

void state::clear() {
    this->isFinal = false;
    this->transitions.clear();
}

void state::copyState (const shared_ptr<state>& s) {
    this->isFinal = s->isFinal;
    this->transitions = s->transitions;
}

bool state::compareState (const shared_ptr<state>& s) const {
//    if ((!this->isFinal and !s->isFinal) and (this->transitions.empty() and s->transitions.empty())) return false;
    return this->isFinal == s->isFinal and this->transitions == s->transitions;
}
