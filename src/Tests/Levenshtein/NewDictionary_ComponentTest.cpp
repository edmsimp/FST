#include "Levenshtein.h"

int main(){
    LevenshteinAutomata automata;

    std::vector<std::string> dictionary = {"squibiri", "squibiribibiri", "squabara", "squibiribabara"};
    std::vector<std::string> word = {"squibir", "squabarab", "squibirib", "squibara"};

    automata.updateDictionary(dictionary);

    for(std::vector<std::string>::iterator it = word.begin(); it != word.end(); it++){
        std::cout << "Levenshtein Distance 1 for " << *it << std::endl;
        std::vector<std::string> words;
        automata.getWords(*it, &words, 10);
    
        for(std::vector<std::string>::iterator jt = words.begin(); jt != words.end(); jt++)
            std::cout << *jt << std::endl;
        
        std::cout << std::endl;
    }   
}