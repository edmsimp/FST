#include "State.h"

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
    return this->isFinal == s->isFinal and this->transitions == s->transitions;
}
