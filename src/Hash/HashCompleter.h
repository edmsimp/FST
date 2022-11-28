#ifndef HASH_COMPLETER
#define HASH_COMPLETER

#include <functional>
#include <unordered_map>
#include <string>
#include <iostream>

class HashCompleter{
public:
    // Constructor and destructor
    HashCompleter();
    ~HashCompleter();

    // Functions
    void trainFromInput(std::string filename);

private:
    // Basic hash table entry
    struct hashWord{
        std::string word;
        int value;
    };

    // Hash Table for string/appearances
    std::unordered_map<std::string, int> table; 
    
    // Auxiliary functions  
    void printTable();

};

#endif