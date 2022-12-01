#include "state.h"

state::state() {
    this->isFinal = false;
    this->transitions.clear();
}

bool state::compareState (const std::shared_ptr<state>& s) const {
    return this->isFinal == s->isFinal and this->transitions == s->transitions;
}
