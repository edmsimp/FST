#include <list>
#include <string>
#include "Levenshtein.h"

int main(){
    LevenshteinAutomata automata;

    std::list<std::string> word = {"zoologist", "write", "wrath", "wolf"};

    for(std::list<std::string>::iterator it = word.begin(); it != word.end(); it++){
        std::cout << "Levenshtein Distance 1 for " << *it << std::endl;
        std::list<std::string> words = automata.getWords(*it);
    
        for(std::list<std::string>::iterator jt = words.begin(); jt != words.end(); jt++)
            std::cout << *jt << std::endl;
        
        std::cout << std::endl;
    }   
}