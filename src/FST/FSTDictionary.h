#include "FSTBaseDefinitions.h"
#include "FSTState.h"

class FSTDictionary {
public:
    FSTDictionary() = default;
    ~FSTDictionary() = default;

    state findState(state s);
    void addState(state s);
    std::vector<state> getStates();

    static dictionary newDictionary();
    static state member(dictionary d, state s);
    static void insert(dictionary d, state s);

private:
    std::vector<state> states;
};

typedef std::shared_ptr<FSTDictionary> dictionary;