#include <iostream>
#include <map>
#include <memory>
#include <vector>

#define FIRST_CHAR ('a');
#define LAST_CHAR ('z');

typedef class stateStruct stateStruct;
typedef std::shared_ptr<stateStruct> state;

typedef class dictionary dictionary;

class stateStruct {
public:
    stateStruct() {
        this->isFinal = false;
    }

    ~stateStruct() = default;

    bool getIsFinal () {
        return this->isFinal;
    }
    void setIsFinal (bool f) {
        this->isFinal = f;
    }

    state getTransition(char c) {
        this->transitions.at(c);
    }

    void setTransition(char c, state s) {
        this->transitions.insert({c, s});
    }

    void clearTransitions() {
        this->transitions.clear();
    }

private:
    std::map<char, state> transitions;
    bool isFinal;
};

state newState () {
    return std::make_shared<stateStruct>();
}

state copyState (state s) {
    state ns = newState();
    *ns = *s;
    return ns;
}

state clearState (state s) {
    s->clearTransitions();
    s->setIsFinal(false);
}

class dictionary {
public:
    dictionary() = default;

    ~dictionary() = default;

    state getTransition (state s, char c) {
        return s->getTransition(c);
    }

    void setTransition (state s, char c, state ns) {
        s->setTransition(c, ns);
    }

private:
    std::vector<state> states;
    state parameterState;
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
