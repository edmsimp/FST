#include <fstream>

#include "FSTCompleter.h"

// TODO: delete main.cpp

int main () {
    std::vector<std::string> input = {"grabs", "grace", "graced", "graceful", "gracefully", "gray"};
    std::vector<std::string> matchStrings (5, "");
    FSTCompleter fstCompleter(input, &matchStrings, 6, 6);
    fstCompleter.autoComplete("grac");
    for (std::string c : matchStrings) std::cout << c << std::endl;
    return 0;
}