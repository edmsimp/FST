#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>


/********* Definitions *********/

#define FIRST_CHAR '\''
#define LAST_CHAR 'z'
#define MAX_WORD_SIZE 50

typedef class stateStruct stateStruct;
typedef std::shared_ptr<stateStruct> state;
typedef class dictionaryStruct dictionaryStruct;
typedef std::shared_ptr<dictionaryStruct> dictionary;

/********* State Struct *********/

class stateStruct {
public:
    stateStruct() = default;

    ~stateStruct() = default;

    bool getIsFinal () {
        return this->isFinal;
    }

    void setIsFinal (bool f) {
        this->isFinal = f;
    }

    state getTransition(char c) {
        return this->transitions.at(c);
    }

    void setTransition(char c, state s) {
        this->transitions.insert({c, s});
    }

    void clearTransitions() {
        this->transitions.clear();
    }

    std::set<std::string> getStrings () {
        return this->strings;
    }

    void setStrings (std::set<std::string> s) {
        this->strings = s;
    }

    std::string getOutput (char c) {
        return this->outputs.at(c);;
    }

    void setOutput (char c, std::string s) {
        this->outputs.insert({c, s});
    }

private:
    std::map<char, state> transitions;
    std::map<char, std::string> outputs; // null if isFinal = true
    std::set<std::string> strings; // null if isFinal = false
    bool isFinal;
};

/********* Auxiliary State Functions *********/

state newState () {
    return std::make_shared<stateStruct>();
}

state getTransition (state s, char c) {
    return s->getTransition(c);
}

void setTransition (state s, char c, state ns) {
    s->setTransition(c, ns);
}

std::set<std::string> stateOutput (state s) {
    return s->getStrings();
}

void setStateOutput (state s, std::set<std::string> so) {
    s->setStrings(so);
}

std::string output (state s, char c) {
    return s->getOutput(c);
}

void setOutput (state s, char c, std::string o) {
    s->setOutput(c, o);
}

/********* Dictionary *********/

class dictionaryStruct {
public:
    dictionaryStruct() = default;

    ~dictionaryStruct() = default;

    state findState (state s) {
        for(std::vector<state>::iterator it = this->states.begin(); it < this->states.end(); it++)
            if (*it == s) return *it;
        return nullptr;
    }

    void addState (state s) {
        this->states.emplace_back(s);
    }

private:
    std::vector<state> states;
    state parameterState;
};

/********* Final Functions *********/

state copyState (state s) {
    state ns = newState();
    *ns = *s;
    return ns;
}

void clearState (state s) {
    s->clearTransitions();
    s->setIsFinal(false);
}

bool compareState (state s1, state s2) {
    return s1 == s2;
}

dictionary newDictionary () {
    return std::make_shared<dictionaryStruct>();
}

state member (dictionary d, state s) {
    return d->findState(s);
}

void insert (dictionary d, state s) {
    d->addState(s);
}

/********* Utils *********/

std::string longestCommonPrefix (std::string arr[], int n) {
    if (n == 0)  return "";
    if (n == 1)  return arr[0];

    sort(arr, arr + n);
    int min = std::min(arr[0].size(), arr[n - 1].size());
    std::string first = arr[0], last = arr[n - 1];
    int i = 0;

    while (i < min && first[i] == last[i])  i++;

    std::string prefix = first.substr(0, i);
    return prefix;
}

std:: string leftDivision (std::string s1, std::string s2) {
    std::string q = "";

    if (s2.length() < s1.length()) return "NULL";
    if (s2.length() == s1.length()) return "";

    int i = 0;
    while (s1[i] == s2[0])  i++;

    for (int j = i; i < s2.length(); j++) {
        q = q + s2[j];
    }

    return q;
}

/********* Program *********/

dictionary minimalTransducerStatesDictionary;

state findMinimized (state s) {
    state r;
    r = member(minimalTransducerStatesDictionary, s);

    if (r == nullptr) {
        r = copyState(s);
        insert(minimalTransducerStatesDictionary, s);
    }

    return r;
}

int main() {
    std::fstream file;

    std::vector<state> tempStates;
    tempStates.resize(MAX_WORD_SIZE, nullptr);
    state initialState;
    std::string previousWord, currentWord, currentOutput,
        wordSuffix, commonPrefix;
    std::string tempString;
    std::set<std::string> tempSet;
    int i, j, prefixLengthPlus1;
    char c;

    minimalTransducerStatesDictionary = newDictionary();

    for (i = 0; i < MAX_WORD_SIZE; ++i) {
        tempStates[i] = newState();
    }

    previousWord = "";
    clearState(tempStates[0]);

    file.open ("dict.txt", std::ios::in);
    if (file.is_open())
        while (!file.eof()) {
            std::getline(file, currentWord);
            // current output should be defined here, but I don't know what it should be
            std::cout << currentWord << std::endl;

            i = 1;
            while (i < currentWord.length() and i < previousWord.length() and currentWord[i] == previousWord[i])
                i++;
            prefixLengthPlus1 = i;

            for (i = prefixLengthPlus1; i < currentWord.length(); i++) {
                clearState(tempStates[i]);
                setTransition(tempStates[i-1], currentWord[i], tempStates[i]);
            }

            if (currentWord != previousWord) {
                tempStates[currentWord.length()]->setIsFinal(true);
                setStateOutput(tempStates[currentWord.length()], {""});
            }

            for (j = 1; j < prefixLengthPlus1 - 1; j++) {
                std::string arr[] = {output(tempStates[j-1], currentWord[j]), currentOutput};
                int n = sizeof(arr);
                commonPrefix = longestCommonPrefix(arr, n);

                wordSuffix = leftDivision(commonPrefix, output(tempStates[j-1], currentWord[j]));
                setOutput(tempStates[j-1], currentWord[j], commonPrefix);

                for (c = FIRST_CHAR; c < LAST_CHAR; c++)
                    if (getTransition(tempStates[j], c) != nullptr)
                        setOutput(tempStates[j], c, wordSuffix + output(tempStates[j], c));

                if (tempStates[j]->getIsFinal()) {
                    tempSet.clear();
                    for (auto string : stateOutput(tempStates[j])) {
                        std::set<std::string>::iterator it;
                        tempSet.insert(it, wordSuffix + tempString);
                        setStateOutput(tempStates[j], tempSet);
                    }
                }
                currentOutput = leftDivision(commonPrefix, currentOutput);
            }
            if (currentWord == previousWord) {
                std::set<std::string> temp = stateOutput(tempStates[currentWord.length()]);
                temp.insert(currentOutput);
                setStateOutput(tempStates[currentWord.length()], temp);
            }
            else {
                setOutput(tempStates[prefixLengthPlus1 - 1], currentWord[prefixLengthPlus1], currentOutput);
            }
            previousWord = currentWord;
        }
        for (i = currentWord.length(); i > 0; i--) {
            setTransition(tempStates[i-1], previousWord[i], findMinimized(tempStates[i]));
        }
        initialState = findMinimized(tempStates[0]);
        // TODO: print transducer

    file.close();
    return 0;
}
