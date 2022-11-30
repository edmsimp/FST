//
// Created by edusi on 29/11/2022.
//
#ifndef FST_FST_H
#define FST_FST_H

#include <iostream>
#include <memory>
#include <vector>

#include "state.h"

#define FIRST_CHAR '\''
#define LAST_CHAR 'z'
#define MAX_WORD_SIZE 20

using namespace std;

class fst {
public:
    fst (vector<string> &input);

    ~fst () = default;

    void insert (const shared_ptr<state>& s);
    void replaceOrRegister (shared_ptr<state>& s);
    void addSuffix (shared_ptr<state>& s, string suffix);
    bool hasChildren (shared_ptr<state>& s);
    string commonPrefix (string s);
    shared_ptr<state> findStateByString (string s);
    shared_ptr<state> lastChild (shared_ptr<state>& s);

    shared_ptr<state> member (const shared_ptr<state>& s);
    vector<shared_ptr<state>> states;
    int id_counter;

    static string getSuffix(string s, string prefix);
    static void printState(const shared_ptr<state>& s);
};


#endif //FST_FST_H
