//
// Created by edusi on 29/11/2022.
//

#include <map>
#include <memory>
#include <set>
#include <string>

#ifndef FST_STATE_H
#define FST_STATE_H

using namespace std;

class state {
public:
    state ();
    ~state () = default;

    void clear ();
    void copyState (const shared_ptr<state>& s);
    bool compareState (const shared_ptr<state>& s) const;

    map<char, shared_ptr<state>> transitions;
    bool isFinal;
};


#endif //FST_STATE_H
