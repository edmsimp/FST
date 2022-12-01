#ifndef FST_FST_H
#define FST_FST_H

#include <iostream>
#include <memory>
#include <vector>

#include "State.h"

class FST {
public:
    // Class constructor and destructor
    FST () = default;
    ~FST () = default;

    /**
     * @brief Function that returns the FST number of states.
     * @return Integer of the corresponding number of states.
     */
    int getNumberOfStates();

    /**
     * @brief Function that loads the input dictionary
     * vector into the FST.
     * @param input Dictionary to be loaded.
     */
    void loadFST(std::vector<std::string> &input);

    /**
     * @brief Function that inserts a state into
     * the FST.
     * @param s State to be inserted into the FST.
     */
    void insert(const std::shared_ptr<State>& s);

    /**
     * @brief Function that insert a state and its sons
     * into the FST or replace it with an existing state
     * in the FST.
     * @param s State to be replaced or registered into
     * the FST.
     */
    void replaceOrRegister(std::shared_ptr<State>& s);

    /**
     * @brief Function to store words that match with the input
     * string into a vector, with quantity defined.
     * @param stringToMatch String to be matched with.
     * @param matchedStrings Strings found on tree that satisfies
     * the input.
     * @param quantityToMatch Quantity of strings the vector should
     * handle.
     */
    void matchStrings(std::string &stringToMatch, std::vector<std::string> &matchedStrings, int &quantityToMatch);

    /**
     * @brief Recursive function to search from a node to find
     * matched strings.
     * @param node Node to search.
     * @param stringToMatch String to be matched with.
     * @param currentString String that represents the current node.
     * @param matchedStrings Strings found on tree that satisfies
     * the input.
     * @param quantityToMatch Quantity of strings the vector should
     * handle.
     */
    void recursiveMatchStrings(std::shared_ptr<State> node, std::string &stringToMatch, std::string &currentString, std::vector<std::string> &matchedStrings, int &quantityToMatch);

    /**
     * @brief Function that create a branch in the FST based on
     * a suffix string.
     * @param s State to start adding the branch.
     * @param suffix String to add.
     */
    static void addSuffix(std::shared_ptr<State>& s, const std::string& suffix);

    /**
     * @brief Function that checks if the state has children.
     * @param s State to check.
     * @return Whether the state has children or not.
     */
    static bool hasChildren(std::shared_ptr<State>& s);

    /**
     * @brief Function that return the common prefix between
     * two words.
     * @param currentWord First word.
     * @param previousWord Second word.
     * @return Common prefix between the strings.
     */
    static std::string commonPrefix(std::string currentWord, std::string previousWord);

    /**
     * @brief Function that returns the state reached by
     * search trough the FST using a given string.
     * @param q0 Initial state of the FST.
     * @param s String to search.
     * @return Final state of the search.
     */
    static std::shared_ptr<State> findStateByString(std::shared_ptr<State> &q0, const std::string& s);

    /**
     * @brief Function to returns the last added transition
     * in a given state.
     * @param s State to search.
     * @return State that derives from the last added transition.
     */
    static std::shared_ptr<State> lastChild(std::shared_ptr<State>& s);

    /**
     * @brief Function that returns the suffix of a word given the prefix.
     * @param s Word to analyse.
     * @param prefix Word prefix.
     * @return Word suffix.
     */
    static std::string getSuffix(std::string s, const std::string& prefix);

    /**
     * @brief Function that returns the state in case it exists in the
     * FST, otherwise it returns NULL.
     * @param s State to analyse.
     * @return State that exists in the FST or NULL.
     */
    std::shared_ptr<State> member(const std::shared_ptr<State>& s);

    std::vector<std::shared_ptr<State>> states; // Vector of states registered into the FST.
};

#endif
