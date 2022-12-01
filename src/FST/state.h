#include <map>
#include <memory>
#include <set>
#include <string>

#ifndef FST_STATE_H
#define FST_STATE_H

class state {
public:
    state ();
    ~state () = default;

    bool compareState (const std::shared_ptr<state>& s) const;

    std::map<char, std::shared_ptr<state>> transitions;
    bool isFinal;
};

#endif //FST_STATE_H
