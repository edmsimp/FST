#include <fstream>

#include "fst.h"

using namespace std;

int main () {
    vector<string> input = {"abacate", "abacaxi"};

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