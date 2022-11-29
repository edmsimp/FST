#include <list>
#include <string>
#include "Levenshtein.h"

int main(){
    LevenshteinAutomata automata;

    std::list<std::string> dictionary = {"squibiri", "squibiribibiri", "squabara", "squibiribabara"};
    std::list<std::string> word = {"squibir", "squabarab", "squibirib", "squibara"};

    automata.updateDictionary(dictionary);

    for(std::list<std::string>::iterator it = word.begin(); it != word.end(); it++){
        std::cout << "Levenshtein Distance 1 for " << *it << std::endl;
        std::list<std::string> words = automata.getWords(*it);
    
        for(std::list<std::string>::iterator jt = words.begin(); jt != words.end(); jt++)
            std::cout << *jt << std::endl;
        
        std::cout << std::endl;
    }   
}