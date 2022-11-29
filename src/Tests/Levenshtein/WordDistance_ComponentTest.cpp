#include <string>

#include "Levenshtein.h"

int main(){
    std::string s1 = "Levenshtein";
    std::string s2 = "Levenshtein";

    LevenshteinAutomata automata;
    std::cout << "Distance between strings: " << std::endl;
    std::cout << s1 << " and " << s2 << std::endl;
    std::cout << "Is: " << automata.levenshteinDistance(s1, s2) << std::endl;
}