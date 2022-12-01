#include <fstream>

#include "FST.h"

using namespace std;

int main () {
    vector<string> input = {"febuary", "january"};

    shared_ptr<FST> fst = make_shared<FST>(input);

    cout << "\n\n PRINT \n\n";

    if (fst->states.empty()) cout << "empty fst";
    else {
        for (const auto& s: fst->states) {
            FST::printState(s);
            cout << "\n";
        }
    }
    cout << "\n";

    return 0;
}