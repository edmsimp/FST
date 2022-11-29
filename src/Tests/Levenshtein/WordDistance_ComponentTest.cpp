#include <string>

#include "Levenshtein.h"

int main(){
    std::string s1 = "Levenshtein";
    std::string s2 = "Levvvvvtein";
    std::string s3 = "Squibiribib";
    std::string s4 = "Squibarabab";

    LevenshteinAutomata automata;
    std::cout << "Strings" << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;

    std::cout << "Distance between s1 and s2 is: " << automata.levenshteinDistance(s1, s2) << std::endl;
    std::cout << "Distance between s1 and s3 is: " << automata.levenshteinDistance(s1, s3) << std::endl;
    std::cout << "Distance between s1 and s4 is: " << automata.levenshteinDistance(s1, s4) << std::endl;
    std::cout << "Distance between s2 and s3 is: " << automata.levenshteinDistance(s2, s3) << std::endl;
    std::cout << "Distance between s2 and s4 is: " << automata.levenshteinDistance(s2, s4) << std::endl;
    std::cout << "Distance between s3 and s4 is: " << automata.levenshteinDistance(s3, s4) << std::endl;
}