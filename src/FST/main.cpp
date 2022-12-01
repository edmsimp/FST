#include <fstream>

#include "fst.h"

using namespace std;

int main () {
    vector<string> input = {"febuary", "january"};

    shared_ptr<fst> FST = make_shared<fst>(input);

    cout << "\n\n PRINT \n\n";

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