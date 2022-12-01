#include "fst.h"

fst::fst (std::vector<std::string> &input) {
    std::shared_ptr<state> q0 = std::make_shared<state>();
    std::string previousWord, currentWord;

    this->states.emplace_back(q0);

    for (auto & i : input) {
        currentWord = i;

        std::string cp = commonPrefix(currentWord, previousWord);
        std::shared_ptr<state> lastState = findStateByString(q0, cp);
        std::string cs = getSuffix(currentWord, cp);

        if (hasChildren(lastState)) {
            replaceOrRegister(lastState);
        }
        addSuffix(lastState, cs);
        previousWord = currentWord;
    }
    replaceOrRegister(q0);
}

std::shared_ptr<state> fst::member (const std::shared_ptr<state>& s) {
    for (auto r : this->states)
        if (r->compareState(s)) return r;
    return nullptr;
}

void fst::insert(const std::shared_ptr<state>& s) {
    this->states.emplace_back(s);
}

std::shared_ptr<state> fst::findStateByString(std::shared_ptr<state> &q0, const std::string& s) {
    std::shared_ptr<state> aux = q0;
    if (q0->transitions.empty()) return q0;
    for (auto c : s)
        aux = aux->transitions.find(c)->second;
    return aux;
}

std::shared_ptr<state> fst::lastChild(std::shared_ptr<state> &s) {
    return s->transitions.rbegin()->second;
}

void fst::addSuffix(std::shared_ptr<state> &s, const std::string& suffix) {
    std::shared_ptr<state> aux = s;
    for (char i : suffix) {
        std::shared_ptr<state> r = std::make_shared<state>();
        aux->transitions.insert({i, r});
        aux = r;
    }
    aux->isFinal = true;
}

bool fst::hasChildren(std::shared_ptr<state> &s) {
    return !s->transitions.empty();
}

std::string fst::commonPrefix(std::string currentWord, std::string previousWord) {
    std::string prefix;
    if (previousWord.empty()) return "";
    int i = 0;
    while (i < currentWord.length() and i < previousWord.length() and currentWord[i] == previousWord[i]) i++;

    for (int j = 0; j < i; j++)
        prefix += currentWord[j];
    return prefix;
}

void fst::replaceOrRegister(std::shared_ptr<state> &s) {
    std::shared_ptr<state> child = lastChild(s);
    if (hasChildren(child))
        replaceOrRegister(child);

    std::shared_ptr<state> q = member(child);
    if (q != nullptr) {
        s->transitions.rbegin()->second = q;
    }
    else
        this->insert(child);
}

std::string fst::getSuffix (std::string s, const std::string& prefix) {
    std::string q;
    for (int i = static_cast<int>(prefix.length()); i < s.length(); i++) {
        q += s[i];
    }
    return q;
}
