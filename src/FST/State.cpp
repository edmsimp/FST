#include "State.h"

State::State() {
    this->isFinal = false;
    this->transitions.clear();
}

bool State::compareState(const std::shared_ptr<State>& s) const {
    return this->isFinal == s->isFinal and this->transitions == s->transitions;
}
