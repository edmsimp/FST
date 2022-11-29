#include <iostream>
#include <string>

int main(){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for(std::string::iterator it = alphabet.begin(); it != alphabet.end(); it++)
        std::cout << *it << ": " << int(*it) << std::endl;

    std::cout << "Shifting index by 97." << std::endl;
    
    for(std::string::iterator it = alphabet.begin(); it != alphabet.end(); it++)
        std::cout << *it << ": " << int(*it) - 97 << std::endl;
}