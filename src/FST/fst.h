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
    int id_counter;
    shared_ptr<state> member (const shared_ptr<state>& s);
    vector<shared_ptr<state>> states;

    fst (vector<string> &input);

    ~fst () = default;

    void insert (const shared_ptr<state>& s);
    shared_ptr<state> findMinimized (shared_ptr<state>& s, int &id_counter);
};


#endif //FST_FST_H
