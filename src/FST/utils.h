//
// Created by edusi on 29/11/2022.
//

#include <iostream>

#include "dictionary.h"

void printState (const shared_ptr<state>& s) {
    map<char, shared_ptr<state>>::iterator it_t;
    map<char, string>::iterator it_o;

    cout << "state " << s->id;
    if (s->isFinal) cout << "(final)";
    cout << "\ntransitions: " << "\n";
    if (s->transitions.empty()) cout << "--- no transitions\n";
    else
        for (it_t = s->transitions.begin(); it_t != s->transitions.end(); it_t++) {
            cout << "--- char: " << it_t->first << ", goes to state " << it_t->second->id << ", with output ";
        }
}

void printDictionary (const shared_ptr<dictionary>& d) {
    if (d->states.empty()) cout << "empty dictionary";
    else {
        for (const auto& s: d->states) {
            printState(s);
            cout << "\n";
        }
    }
    cout << "\n";
}