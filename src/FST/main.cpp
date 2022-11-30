#include <fstream>

#include "dictionary.h"
#include "utils.h"

#define FIRST_CHAR '\''
#define LAST_CHAR 'z'
#define MAX_WORD_SIZE 20

using namespace std;

int id_counter = 0;

shared_ptr<state> findMinimized (shared_ptr<dictionary>& d, shared_ptr<state>& s) {
    shared_ptr<state> r = make_shared<state>(id_counter);
    r = d->member(s);
    if (r == nullptr) {
        r->copyState(s);
        d->insert(r);
    }
    return r;
}

shared_ptr<dictionary> createFST (fstream& input) {
    std::vector<shared_ptr<state>> tempStates;
    tempStates.resize(MAX_WORD_SIZE, nullptr);
    shared_ptr<state> initialState;
    string previousWord, currentWord, currentOutput, wordSuffix, commonPrefix, tempString;
    set<string> tempSet;
    int i, j, prefixLenPlus1;
    char c;

    shared_ptr<dictionary> MTS = make_shared<dictionary>();
    for (i = 0; i < MAX_WORD_SIZE; i++)
        tempStates[i] = make_shared<state>(id_counter);
    tempStates[0]->clear();

    while (!input.eof()) {
        input >> currentWord;
        input >> currentOutput; // ???

        i = 0;
        while (i < previousWord.length() and i < currentWord.length() and previousWord[i] == currentWord[i])
            i++;
        prefixLenPlus1 = i;

        // TODO continue


    }
}

int main () {

    // Tests

    fstream a;
    a.open("dict.txt", ios::in);
    createFST (a);
    a.close();

    return 0;
}