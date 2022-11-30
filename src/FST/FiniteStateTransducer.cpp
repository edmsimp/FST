#include "FiniteStateTransducer.h"

FST::FST(){
    minimalTransducerStatesDictionary = FSTDictionary::newDictionary();
}

std::string FST::longestCommonPrefix (std::string arr[], int n) {
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

std::string FST::leftDivision (std::string s1, std::string s2) {
    std::string q = "";

    if (s2.length() < s1.length()) return "NULL";
    if (s2.length() == s1.length()) return "";

    int i = 0;
    while (s1[i] == s2[i])  i++;

    for (int j = i; j < s2.length(); j++) {
        q = q + s2[j];
    }

    return q;
}

state FST::findMinimized(state s) {
    state r = FSTState::newState();
    r = FSTDictionary::member(minimalTransducerStatesDictionary, s);

    if (r == nullptr) {
        r = FSTState::copyState(s);
        FSTDictionary::insert(minimalTransducerStatesDictionary, r);
    }

    return r;
}

void printFST(state s) {
    if (!s->getOutputsMap().empty()) {
        std::map<char, std::string>::iterator it;
        for (it = s->getOutputsMap().begin(); it != s->getOutputsMap().end(); it++) {
            if (it->second != "") std::cout << "    " << it->first << ": " << it->second << std::endl;
        }
    }

    if (!s->getTransitionsMap().empty()) {
        std::map<char, state>::iterator it;
        for (it = s->getTransitionsMap().begin(); it != s->getTransitionsMap().end(); it++) {
            if (it->second != nullptr) std::cout << "    " << it->first << ": " << it->second << std::endl;
        }
    } else std::cout << "a";
}

