#include <iostream>
#include <fstream>
#include <memory>

#include "dictionary.h"

#define FIRST_CHAR '\''
#define LAST_CHAR 'z'

using namespace std;

shared_ptr<state> findMinimized (shared_ptr<dictionary>& d, shared_ptr<state>& s) {
    shared_ptr<state> r = make_shared<state>();
    r = d->member(s);
    if (r == nullptr) {
        r->copyState(s);
        d->insert(r);
    }
    return r;
}

shared_ptr<dictionary> createFST (fstream input) {

    shared_ptr<dictionary> MTS = make_shared<dictionary>();
    // TODO
}

int main () {

}