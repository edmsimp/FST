//
// Created by edusi on 29/11/2022.
//

#include "fst.h"

using namespace std;

fst::fst (vector<string> &input) {

    shared_ptr<state> q0 = make_shared<state>();
    this->states.emplace_back(q0);

    for (int i = 0; i < input.size(); i++) {
        string word = input[i];
        string cp = commonPrefix(word);
        shared_ptr<state> lastState = findStateByString(cp);
        string cs = getSuffix(word, cp);

        if (hasChildren(lastState))
            replaceOrRegister(lastState);
        addSuffix(lastState, cs);
    }
    replaceOrRegister(q0);
}

shared_ptr<state> fst::member (const shared_ptr<state>& s) {
    for (auto r : this->states)
        if (r->compareState(s)) return r;
    return nullptr;
}

void fst::insert(const shared_ptr<state>& s) {
    this->states.emplace_back(s);
}

shared_ptr<state> fst::findStateByString(string s) {
    shared_ptr<state> aux = this->states[0];
    for (auto c : s) {
        aux = aux->transitions.find(c)->second;
        if (aux != aux->transitions.end()->second)
            return aux;
    }
    return this->states[0];
}

shared_ptr<state> fst::lastChild(shared_ptr<state> &s) {
  //  map<char, shared_ptr<state>>::iterator it;
  //  for (it = s->transitions.begin(); it != s->transitions.end(); it++);
  //   cout << (it)-> first;
    return s->transitions.rend()->second;
}

void fst::addSuffix(shared_ptr<state> &s, string suffix) {
    shared_ptr<state> aux = s;
    for (int i = 0; i < suffix.size(); i++) {
        shared_ptr<state> r = make_shared<state>();
        aux->transitions.insert({suffix[i], r});
        aux = r;
    }
    aux->isFinal = true;
}

bool fst::hasChildren(shared_ptr<state> &s) {
    return !s->transitions.empty();
}

string fst::commonPrefix(string s) {
    string prefix;
    shared_ptr<state> aux = this->states[0];
    for (auto c : s) {
        if (aux->transitions.find(c) != aux->transitions.end())
            prefix = prefix + c;
    }
    return prefix;
}

void fst::replaceOrRegister(shared_ptr<state> &s) {
    shared_ptr<state> child = lastChild(s);
    if (hasChildren(child))
        replaceOrRegister(child);

    shared_ptr<state> q = member(child);
    if (q != nullptr) {
        lastChild(s) = q;
    }
    else
        this->insert(child);
}

string fst::getSuffix (string s, string prefix) {
    string q;
    for (int i = prefix.length(); i < s.length(); i++) {
        q = q + s[i];
    }

    return q;
}

void fst::printState (const shared_ptr<state>& s) {
    map<char, shared_ptr<state>>::iterator it_t;
    map<char, string>::iterator it_o;
    int id = 0;
    cout << "state " << id;
    if (s->isFinal) cout << "(final)";
    cout << "\ntransitions: " << "\n";
    if (s->transitions.empty()) cout << "--- no transitions\n";
    else
        for (it_t = s->transitions.begin(); it_t != s->transitions.end(); it_t++) {
            id++;
            cout << "--- char: " << it_t->first << ", goes to state " << id << endl;
        }
}
