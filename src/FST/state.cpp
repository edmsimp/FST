//
// Created by edusi on 29/11/2022.
//

#include "state.h"

state::state(int &i) {
    this->isFinal = false;
    this->id = i;
    i++;
}

void state::clear() {
    this->isFinal = false;
    this->transitions.clear();
    this->outputs.clear();
    this->stateOutput.clear();
}

void state::copyState (const shared_ptr<state>& s) {
    this->isFinal = s->isFinal;
    this->transitions = s->transitions;
    this->outputs = s->outputs;
    this->stateOutput = s->stateOutput;
}

bool state::compareState (const shared_ptr<state>& s) const {
    return this->isFinal == s->isFinal and
            this->transitions == s->transitions and
            this->outputs == s->outputs and
            this->stateOutput == s->stateOutput;
}
