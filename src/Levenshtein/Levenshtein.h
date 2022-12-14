#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class LevenshteinAutomata {
public:
    // Class constructor and destructor
    LevenshteinAutomata();
    LevenshteinAutomata(std::vector<std::string> &dictionary);
    ~LevenshteinAutomata();

    /**
     * @brief Function that resets the dictionary used 
     * by the Levenshtein Automata to the default one, 
     * which is the Linux dictionary for American English
     * words.
     */
   void resetDictionary();

    /**
     * @brief Function to update the words whose distances
     * will be calculated when a new word is passed to the
     * automata.
     * @param newDict List containing the new dictionary
     * with the words.
     */
   void updateDictionary(std::vector<std::string> &newDict);

    /**
     * @brief Function that returns the list of words with
     * Levenshtein distance 1 from the current word.
     * @param word Word whose distances will be calculated 
     * by the Levenshtein Automata.
     * @param matchedStrings Pointer to vector onto which the 
     * strings with Levenshtein distance 1 will be placed.
     * @param maxMatches Maximum number of words to be matched.
     */
    void getWords(std::string word, std::vector<std::string> *matchedStrings, int maxMatches);

    /**
     * @brief Function that calculates the Levenshtein distance
     * of the first string in relation to the second one.
     * @param firstString First string.
     * @param secondString Second string.
     * @return Levenshtein Distance from first string to second string.
     */
    int levenshteinDistance(std::string firstString, std::string secondString);

private:
    std::list<std::string> dictionary; // The dictionary that stores the words.
};

#endif