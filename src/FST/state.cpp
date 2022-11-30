//
// Created by edusi on 29/11/2022.
//

#include "state.h"

state::state(int &i) {
    this->isFinal = false;
    this->id = i;
    this->transitions.clear();
    i++;
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
    return this->isFinal == s->isFinal and this->transitions == s->transitions;
}
