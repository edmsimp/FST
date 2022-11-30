#include "FSTBaseDefinitions.h"

class FSTState {
public:
    FSTState() = default;
    ~FSTState() = default;

    // Functions that are part of the state
    bool getIsFinal();
    void setIsFinal(bool f);
    void setTransition(char c, state s);
    void clearTransitions();
    void setStrings(std::set<std::string> s);
    void setOutput(char c, std::string s);
    state getTransition(char c);
    std::set<std::string> getStrings();
    std::string getOutput(char c);
    std::map<char, std::string> getOutputsMap();
    std::map<char, state> getTransitionsMap();

    // Auxiliary functions
    static state newState();
    static state getTransition(state s, char c);
    static void setTransition(state s, char c, state ns);
    static void setStateOutput(state s, std::set<std::string> so);
    static void setOutput(state s, char c, std::string o);
    static std::set<std::string> stateOutput(state s);
    static std::string output(state s, char c);

    // Final functions
    static state copyState(state s);
    static void clearState(state s);
    bool compareState(state s1, state s2);
    
private:
    std::map<char, state> transitions;
    std::map<char, std::string> outputs; // null if isFinal = true
    std::set<std::string> strings; // null if isFinal = false
    bool isFinal;
};

typedef std::shared_ptr<FSTState> state;