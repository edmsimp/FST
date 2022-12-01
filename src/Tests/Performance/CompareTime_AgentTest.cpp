#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <list>

#include "GenericCompleter.h"

std::chrono::_V2::high_resolution_clock::time_point startTime, endTime;

void updateTime(std::chrono::_V2::high_resolution_clock::time_point &timestamp){
    timestamp = std::chrono::high_resolution_clock::now();
}

void writeTime(std::ofstream &outputFile, std::string word){
    outputFile << word << ", " << (std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime)).count() << std::endl;
}

int main(){
    // Preparing the output files.  ##################################################################
    std::ofstream levenshteinOut, fstOut, treeOut;
    
    time_t programTimestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    levenshteinOut.open("levenshtein_statistics.csv");
    fstOut.open("fst_statistics.csv");
    treeOut.open("tree_statistics.csv");
    
    if(!levenshteinOut || !fstOut || !treeOut){
        std::cerr << "Error opening an output file !" << std::endl;
        return 1;
    }
    
    levenshteinOut << "string, executionTime (ns)" << std::endl;
    fstOut << "string, executionTime (ns)" << std::endl;
    treeOut << "string, executionTime (ns)" << std::endl;


    // Loading American Dictionary. ##################################################################
    std::ifstream fs;
    fs.open("/usr/share/dict/american-english");

    if(!fs.is_open())
        throw std::runtime_error("Could not open default linux dictionary file!");

    std::vector<std::string> dictionary;
    std::string currentLine;

    while(std::getline(fs, currentLine))
        dictionary.push_back(currentLine);

    fs.close();


    // Preparing some test strings. ##################################################################
    std::vector<std::string> answers = {};
    
    std::list<std::string> alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", 
                                       "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    std::list<std::string> testWord = {"Apo", "Bra", "Bat", "Bee", "Bob", "Cam", "Car", "Cat", "Cro",
                                       "Dao", "Dog", "Ele", "Fra", "Gar", "Gre", "Hog", "Int", "Joe",
                                       "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa",
                                       "aaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaa", "aaaaaaaaaaaa"};

    // Startup tests.               ##################################################################
    // Create Levenshtein Completer.
    updateTime(startTime);
    LevenshteinCompleter levenCompleter(dictionary, &answers, 10, 10);
    updateTime(endTime);
    writeTime(levenshteinOut, "createDict");

    // Create Balanced Tree Completer.
    updateTime(startTime);
    BalancedTreeCompleter treeCompleter(dictionary, &answers, 10, 10);
    updateTime(endTime);
    writeTime(treeOut, "createDict");

    // Create FST Completer.
    updateTime(startTime);
    //BalancedTreeCompleter treeCompleter(dictionary, &answers, 10, 10);
    updateTime(endTime);
    writeTime(fstOut, "createDict");


    // Generic Completer.
    GenericCompleter genCompleter(dictionary, answers, 10, 10);


    // String tests.                ##################################################################
    // Alphabet
    std::cout << "Testing letters..." << std::endl;
    for(std::list<std::string>::iterator it = alphabet.begin(); it != alphabet.end(); it++){
        // Levenshtein
        genCompleter.selectCompleter(2);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(levenshteinOut, *it);

        // Tree
        genCompleter.selectCompleter(1);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(treeOut, *it);

        // FST
        genCompleter.selectCompleter(3);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(fstOut, *it);
    }

    // Strings
    std::cout << "Testing strings..." << std::endl;
    for(std::list<std::string>::iterator it = testWord.begin(); it != testWord.end(); it++){
        // Levenshtein
        genCompleter.selectCompleter(2);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(levenshteinOut, *it);

        // Tree
        genCompleter.selectCompleter(1);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(treeOut, *it);

        // FST
        genCompleter.selectCompleter(3);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(fstOut, *it);
    }

    // 100 random dictionary words
    std::cout << "Testing 100 random dictionary words..." << std::endl;
    testWord.clear();
    while(testWord.size() < 100){
        testWord.push_back(dictionary[std::rand() % dictionary.size()]);
    }

    for(std::list<std::string>::iterator it = testWord.begin(); it != testWord.end(); it++){
        // Levenshtein
        genCompleter.selectCompleter(2);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(levenshteinOut, *it);

        // Tree
        genCompleter.selectCompleter(1);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(treeOut, *it);

        // FST
        genCompleter.selectCompleter(3);
        updateTime(startTime);
        genCompleter.autoComplete(*it);
        updateTime(endTime);
        
        writeTime(fstOut, *it);
    }
}