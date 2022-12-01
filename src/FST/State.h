#ifndef FST_STATE_H
#define FST_STATE_H

#include <map>
#include <memory>
#include <set>
#include <string>

class State {
public:
    State();
    ~State() = default;

    bool compareState(const std::shared_ptr<State>& s) const;

    std::map<char, std::shared_ptr<State>> transitions;
    bool isFinal;
};

#endif
