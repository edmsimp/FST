//
// Created by edusi on 29/11/2022.
//

#include "dictionary.h"

shared_ptr<state> dictionary::member (const shared_ptr<state>& s) {
    for (auto r : this->states)
        if (r->compareState(s)) return r;
    return nullptr;
}

void dictionary::insert(const shared_ptr<state>& s) {
    this->states.emplace_back(s);
}
