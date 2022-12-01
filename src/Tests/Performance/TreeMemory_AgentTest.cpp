#include <fstream>
#include "BalancedTreeCompleter.h"

int main(){
    std::vector<std::string> dictionary;
    std::vector<std::string> matches;

    std::ifstream fs;
    fs.open("/usr/share/dict/american-english");

    if(!fs.is_open())
        throw std::runtime_error("Could not open default linux dictionary file!");

    std::string currentLine;

    while(std::getline(fs, currentLine))
        dictionary.push_back(currentLine);

    fs.close();

    BalancedTreeCompleter completer(dictionary, &matches, 10, 10);
}