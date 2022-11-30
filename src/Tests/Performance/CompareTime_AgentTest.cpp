#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <list>

#include "Levenshtein.h"
#include "BalancedTreeCompleter.h"

std::chrono::_V2::high_resolution_clock::time_point startTime, endTime;

void updateTime(std::chrono::_V2::high_resolution_clock::time_point &timestamp){
    timestamp = std::chrono::high_resolution_clock::now();
}

void writeTime(std::ofstream &outputFile, std::string word){
    outputFile << word << ", " << (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime)).count() << std::endl;
}

int main(){
    // Preparing the output files.  ##################################################################
    std::ofstream levenshteinOut, fstOut, treeOut;
    levenshteinOut.open("levenshtein_statistics.csv");
    fstOut.open("fst_statistics.csv");
    treeOut.open("tree_statistics.csv");
    
    if(!levenshteinOut || !fstOut || !treeOut){
        std::cerr << "Error opening an output file !" << std::endl;
        return 1;
    }
    
    levenshteinOut << "string, executionTime (ms)" << std::endl;
    fstOut << "string, executionTime (ms)" << std::endl;
    treeOut << "string, executionTime (ms)" << std::endl;


    // Preparing some test strings. ##################################################################
    std::list<std::string> alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", 
                                       "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    std::list<std::string> testWord = {"Apo", "Bra", "Bat", "Bee", "Bob", "Cam", "Car", "Cat", "Cro",
                                       "Dao", "Dog", "Ele", "Fra", "Gar", "Gre", "Hog", "Int", "Joe"};


    // Startup tests.               ##################################################################
    // Create Levenshtein Completer.
    updateTime(startTime);
    LevenshteinAutomata levenCompleter;
    updateTime(endTime);
    writeTime(levenshteinOut, "createDict");

    // Create Balanced Tree Completer.

    // Levenshtein string tests.    ##################################################################
    // Alphabet
    for(std::list<std::string>::iterator it = alphabet.begin(); it != alphabet.end(); it++){
        std::cout << "Testing " << *it << "... ";
        updateTime(startTime);
        levenCompleter.getWords(*it);
        updateTime(endTime);
        
        writeTime(levenshteinOut, *it);
        std::cout << "Levenshtein... ";


        std::cout << std::endl;
    }

    // Strings
    for(std::list<std::string>::iterator it = testWord.begin(); it != testWord.end(); it++){
        std::cout << "Testing " << *it << "... ";
        updateTime(startTime);
        levenCompleter.getWords(*it);
        updateTime(endTime);
        
        writeTime(levenshteinOut, *it);
        std::cout << "Levenshtein... ";


        std::cout << std::endl;
    }

}