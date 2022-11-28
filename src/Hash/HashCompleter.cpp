#include "HashCompleter.h"


HashCompleter::HashCompleter(){
    // Set the hash table to an empty one.
    table = {};
}

HashCompleter::~HashCompleter(){

}

void HashCompleter::trainFromInput(std::string filename){
    
}

void HashCompleter::printTable(){
    for(auto it = table.begin(); it != table.end(); it++)
        std::cout << "[" << it.
}