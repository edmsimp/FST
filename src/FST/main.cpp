#include <fstream>

#include "fst.h"

using namespace std;

int main () {
    vector<string> input = {"abacate", "car"};
    // int id1 = 2;
    // int id2 = 5;

    // shared_ptr<state> state1 = make_shared<state>(id1);
    // shared_ptr<state> state2 = make_shared<state>(id2);
    // state1->transitions.insert({'c', state2});

    // std::cout << state1->compareState(state2) << endl;

    //fst FST(input);

    shared_ptr<fst> FST = make_shared<fst>(input);

    if (FST->states.empty()) cout << "empty fst";
    else {
        for (const auto& s: FST->states) {
            fst::printState(s);
            cout << "\n";
        }
    }
    cout << "\n";

    return 0;
}