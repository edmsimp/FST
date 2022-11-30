//
// Created by edusi on 29/11/2022.
//

#include <memory>
#include <vector>

#include "state.h"

#ifndef FST_DICTIONARY_H
#define FST_DICTIONARY_H

using namespace std;

class dictionary {
public:
    dictionary () = default;
    ~dictionary () = default;

    shared_ptr<state> member (const shared_ptr<state>& s);
    void insert (const shared_ptr<state>& s);

    vector<shared_ptr<state>> states;
};


#endif //FST_DICTIONARY_H
