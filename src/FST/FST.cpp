#include "FST.h"

void FST::loadFST(std::vector<std::string> &input) {
    std::shared_ptr<State> q0 = std::make_shared<State>();
    std::string previousWord, currentWord;

    this->states.emplace_back(q0);

    for (auto & i : input) {
        currentWord = i;

        std::string cp = commonPrefix(currentWord, previousWord);
        std::shared_ptr<State> lastState = findStateByString(q0, cp);
        std::string cs = getSuffix(currentWord, cp);

        if (hasChildren(lastState)) {
            replaceOrRegister(lastState);
        }
        addSuffix(lastState, cs);
        previousWord = currentWord;
    }
    replaceOrRegister(q0);
}

std::shared_ptr<State> FST::member(const std::shared_ptr<State>& s) {
    for (auto r : this->states)
        if (r->compareState(s)) return r;
    return nullptr;
}

void FST::insert(const std::shared_ptr<State>& s) {
    this->states.emplace_back(s);
}

std::shared_ptr<State> FST::findStateByString(std::shared_ptr<State> &q0, const std::string& s) {
    std::shared_ptr<State> aux = q0;
    if (q0->transitions.empty()) return q0;
    for (auto c : s)
        aux = aux->transitions.find(c)->second;
    return aux;
}

std::shared_ptr<State> FST::lastChild(std::shared_ptr<State> &s) {
    return s->transitions.rbegin()->second;
}

void FST::addSuffix(std::shared_ptr<State> &s, const std::string& suffix) {
    std::shared_ptr<State> aux = s;
    for (char i : suffix) {
        std::shared_ptr<State> r = std::make_shared<State>();
        aux->transitions.insert({i, r});
        aux = r;
    }
    aux->isFinal = true;
}

bool FST::hasChildren(std::shared_ptr<State> &s) {
    return !s->transitions.empty();
}

std::string FST::commonPrefix(std::string currentWord, std::string previousWord) {
    std::string prefix;
    if (previousWord.empty()) return "";
    int i = 0;
    while (i < currentWord.length() and i < previousWord.length() and currentWord[i] == previousWord[i]) i++;

    for (int j = 0; j < i; j++)
        prefix += currentWord[j];
    return prefix;
}

void FST::replaceOrRegister(std::shared_ptr<State> &s) {
    std::shared_ptr<State> child = lastChild(s);
    if (hasChildren(child))
        replaceOrRegister(child);

    std::shared_ptr<State> q = member(child);
    if (q != nullptr) {
        s->transitions.rbegin()->second = q;
    }
    else
        this->insert(child);
}

std::string FST::getSuffix (std::string s, const std::string& prefix) {
    std::string q;
    for (int i = static_cast<int>(prefix.length()); i < s.length(); i++) {
        q += s[i];
    }
    return q;
}

void FST::matchStrings(std::string &stringToMatch, std::vector<std::string> &matchedStrings, int &quantityToMatch) {
    if (stringToMatch == "") {
        return;
    }

    char c;
    int i = 0;
    std::string currentString;
    std::shared_ptr<State> s = this->states[0];

    while (currentString != stringToMatch) {
        c = stringToMatch[i];
        if (s->transitions.find(c) == s->transitions.end())
            return;
        s = s->transitions.find(c)->second;
        currentString = currentString + c;
        i++;
    }

    this->recursiveMatchStrings(s, stringToMatch, currentString, matchedStrings, quantityToMatch);
}

void FST::recursiveMatchStrings(std::shared_ptr<State> node, std::string &stringToMatch, std::string &currentString, 
                                std::vector<std::string> &matchedStrings, int &quantityToMatch) {
    if (quantityToMatch == 0) {
        return;
    }

    if (node->isFinal) {
        matchedStrings.push_back(currentString);
        quantityToMatch--;
    }

    for (auto it = node->transitions.begin(); it != node->transitions.end(); it++) {
        currentString = currentString + it->first;
        this->recursiveMatchStrings(it->second, stringToMatch, currentString, matchedStrings, quantityToMatch);
    }

    currentString = currentString.substr(0, currentString.size() - 1);
}
