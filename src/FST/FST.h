#ifndef FST_FST_H
#define FST_FST_H

#include <iostream>
#include <memory>
#include <vector>
#include "State.h"

class FST {
public:
    FST () = default;
    ~FST () = default;

    void loadFST(std::vector<std::string> &input);
    void insert(const std::shared_ptr<State>& s);
    void replaceOrRegister(std::shared_ptr<State>& s);
    void matchStrings(std::string &stringToMatch, std::vector<std::string> &matchedStrings, int &quantityToMatch);
    void recursiveMatchStrings(std::shared_ptr<State> node, std::string &stringToMatch, std::string &currentString, std::vector<std::string> &matchedStrings, int &quantityToMatch);
    static void addSuffix(std::shared_ptr<State>& s, const std::string& suffix);
    static bool hasChildren(std::shared_ptr<State>& s);
    static std::string commonPrefix(std::string currentWord, std::string previousWord);
    static std::shared_ptr<State> findStateByString(std::shared_ptr<State> &q0, const std::string& s);
    static std::shared_ptr<State> lastChild(std::shared_ptr<State>& s);
    static std::string getSuffix(std::string s, const std::string& prefix);
    std::shared_ptr<State> member(const std::shared_ptr<State>& s);

    std::vector<std::shared_ptr<State>> states;
};

#endif
