#ifndef FST_FST_H
#define FST_FST_H

#include <iostream>
#include <memory>
#include <vector>

#include "state.h"

class fst {
public:
    explicit fst (std::vector<std::string> &input);
    ~fst () = default;

    void insert (const std::shared_ptr<state>& s);
    void replaceOrRegister (std::shared_ptr<state>& s);
    static void addSuffix (std::shared_ptr<state>& s, const std::string& suffix);
    static bool hasChildren (std::shared_ptr<state>& s);
    static std::string commonPrefix (std::string currentWord, std::string previousWord);
    static std::shared_ptr<state> findStateByString (std::shared_ptr<state> &q0, const std::string& s);
    static std::shared_ptr<state> lastChild (std::shared_ptr<state>& s);
    std::shared_ptr<state> member (const std::shared_ptr<state>& s);
    static std::string getSuffix(std::string s, const std::string& prefix);

    std::vector<std::shared_ptr<state>> states;
};

#endif //FST_FST_H
