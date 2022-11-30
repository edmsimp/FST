//
// Created by edusi on 29/11/2022.
//

#include "fst.h"
#include "utils.h"

using namespace std;

fst::fst (vector<string> &input) {
    this->id_counter = 0;
    std::vector<shared_ptr<state>> tempStates;
    tempStates.resize(MAX_WORD_SIZE, nullptr);
    shared_ptr<state> initialState;
    string previousWord, currentWord, wordSuffix, commonPrefix, tempString;
    int i, j, prefixLenPlus1;
    char c;

    // begin

    for (i = 0; i < MAX_WORD_SIZE; i++)
        tempStates[i] = make_shared<state>(id_counter);

    id_counter = 0;
        
    // tempStates[0]->clear();
    previousWord = "";

    for (int k = 0; k < input.size(); k++) {
        currentWord = input[k];

        //cout << currentWord << endl;

        i = 0;
        while (i < previousWord.length() and i < currentWord.length() and previousWord[i] == currentWord[i])
            i++;
        prefixLenPlus1 = i;

        // TODO: o que isso faz?

        for (i = previousWord.length() - 1; i > prefixLenPlus1; i--) {
            tempStates[i-1]->transitions.insert({previousWord[i], this->findMinimized(tempStates[i], id_counter)});
        }

        for (i = prefixLenPlus1; i < currentWord.length(); i++) {
            tempStates[i]->clear();
            tempStates[i]->transitions.insert({currentWord[i], this->findMinimized(tempStates[i+1], id_counter)});
        }

        if (currentWord.compare(previousWord) != 0) {
            tempStates[currentWord.length()]->isFinal = true;
        }

        // foudase
        // for (int j = 1; j < )

        previousWord = currentWord;        
    }

    for (i = currentWord.length() - 1; i > 1; i--) {
        shared_ptr<state> cu = this->findMinimized(tempStates[i], id_counter);
        tempStates[i-1]->transitions.insert({previousWord[i], cu});
    }

    for (auto s : tempStates) {
        if (s) {
            printState(s);
        }
    }

     // initialState = this->findMinimized(tempStates[0], id_counter);
}

shared_ptr<state> fst::member (const shared_ptr<state>& s) {
    for (auto r : this->states)
        if (r->compareState(s)) return r;
    return nullptr;
}

void fst::insert(const shared_ptr<state>& s) {
    this->states.emplace_back(s);
}

shared_ptr<state> fst::findMinimized (shared_ptr<state>& s, int &id_counter) {
    shared_ptr<state> r = make_shared<state>(id_counter);
    r = this->member(s);
    if (r == nullptr) {
        r = make_shared<state>(id_counter);
        id_counter--;
        r->copyState(s);
        this->insert(r);
    }
    return r;
}
