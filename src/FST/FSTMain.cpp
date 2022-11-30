#include "FiniteStateTransducer.h"

int main() {
    std::fstream file;

    std::vector<state> tempStates;
    tempStates.resize(MAX_WORD_SIZE, nullptr);
    state initialState;
    std::string previousWord, currentWord, currentOutput, wordSuffix, commonPrefix;
    std::string tempString;
    std::set<std::string> tempSet;
    int i, j, prefixLengthPlus1;
    char c;

    FST fst;

    for (i = 0; i < MAX_WORD_SIZE; ++i) {
        tempStates[i] = FSTState::newState();
    }

    previousWord = "";
    FSTState::clearState(tempStates[0]);

    file.open ("dict.txt", std::ios::in);
    
    if (file.is_open())
        while (!file.eof()) {
            std::getline(file, currentWord);
            // current output should be defined here, but I don't know what it should be
            currentOutput = currentWord;

            i = 1;
            while (i < currentWord.length() and i < previousWord.length() and currentWord[i] == previousWord[i])
                i++;
            prefixLengthPlus1 = i;

            for (i = previousWord.length(); i >= prefixLengthPlus1; i--) {
                FSTState::setTransition(tempStates[i-1], previousWord[i], fst.findMinimized(tempStates[i]));
            }

            for (i = prefixLengthPlus1; i < currentWord.length(); i++) {
                FSTState::clearState(tempStates[i]);
                FSTState::setTransition(tempStates[i-1], currentWord[i], tempStates[i]);
            }

            if (currentWord != previousWord) {
                tempStates[currentWord.length()]->setIsFinal(true);
                FSTState::setStateOutput(tempStates[currentWord.length()], {});
            }

            for (j = 1; j < prefixLengthPlus1; j++) {
                std::string arr[] = {FSTState::output(tempStates[j-1], currentWord[j]), currentOutput};
                commonPrefix = fst.longestCommonPrefix(arr, 2);

                wordSuffix = fst.leftDivision(commonPrefix, FSTState::output(tempStates[j-1], currentWord[j]));
                FSTState::setOutput(tempStates[j-1], currentWord[j], commonPrefix);

                for (c = FIRST_CHAR; c <= LAST_CHAR; c++)
                    if (FSTState::getTransition(tempStates[j], c) != nullptr)
                        FSTState::setOutput(tempStates[j], c, wordSuffix + FSTState::output(tempStates[j], c));

                if (tempStates[j]->getIsFinal()) {
                    tempSet.clear();
                    for (auto string : FSTState::stateOutput(tempStates[j])) {
                        tempSet.insert(wordSuffix + tempString);
                        FSTState::setStateOutput(tempStates[j], tempSet);
                    }
                }
                currentOutput = fst.leftDivision(commonPrefix, currentOutput);
            }
            if (currentWord == previousWord) {
                std::set<std::string> temp = FSTState::stateOutput(tempStates[currentWord.length()]);
                temp.insert(currentOutput);
                FSTState::setStateOutput(tempStates[currentWord.length()], temp);
            }
            else {
                FSTState::setOutput(tempStates[prefixLengthPlus1 - 1], currentWord[prefixLengthPlus1], currentOutput);
            }
            previousWord = currentWord;
        }
        for (i = currentWord.length(); i > 0; i--) {
            FSTState::setTransition(tempStates[i-1], previousWord[i], fst.findMinimized(tempStates[i]));
        }
        initialState = fst.findMinimized(tempStates[0]);

    file.close();
    fst.printFST(initialState);

    return 0;
}