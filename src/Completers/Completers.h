#ifndef COMPLETERS
#define COMPLETERS

#include "BalancedTreeCompleter.h"

class Completers {
private:
    // TODO: change completers 2 and 3
    BalancedTreeCompleter *completer1;

    BalancedTreeCompleter *completer2;

    BalancedTreeCompleter *completer3;

public:
    Completers (std::vector<std::string> &dictionary, std::vector<std::string> &matchStrings, int quantityToMatch, int maxQuantityToMatch);

    BalancedTreeCompleter * selectCompleter(int completerId);
};

#endif