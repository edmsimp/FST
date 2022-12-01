#include <fstream>

#include "FST.h"

// TODO: delete main.cpp

int main () {
    FST fst;
    std::vector<std::string> input = {"febuary", "january"};
    fst.loadFST(input);
    return 0;
}