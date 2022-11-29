#include <string>
#include <vector>
#include "BalancedTreeCompleter.h"
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border

int main(int argc, const char* argv[]) {
    using namespace ftxui;

    int quantityToMatch = 5;
    std::string currentString;
    std::vector<std::string> dictionary = {"grabs", "grace", "graced", "graceful", "gracefully", "gray"};
    std::vector<std::string> matchStrings (5, "");

    BalancedTreeCompleter completer = BalancedTreeCompleter(dictionary, matchStrings, quantityToMatch);

    Component inputCurrentString = Input(&currentString, "Type here to search");

    auto component = Container::Vertical({
        inputCurrentString
    });

    auto renderer = Renderer(component, [&] {
        completer.autoComplete(currentString);
        return vbox({
                    hbox(text(" Search : "), inputCurrentString->Render()),
                    separator(),
                    hbox(text(" "), text(matchStrings[0])),
                    hbox(text(" "), text(matchStrings[1])),
                    hbox(text(" "), text(matchStrings[2])),
                    hbox(text(" "), text(matchStrings[3])),
                    hbox(text(" "), text(matchStrings[4])),
                }) |
                border;
    });

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);
}