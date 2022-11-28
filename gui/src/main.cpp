#include <string>
#include <vector>
 
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border

void findMatches(std::vector<std::string> *dictionary, std::string key_to_find, std::vector<std::string> *matches) {
    if (key_to_find == "") {
        for (int i = 0; i < matches->size(); i++) {
            (*matches)[i] = "";
        }
        return;
    }

    int j = 0;
    for (int i = 0; i < dictionary->size(); i++) {
        std::string toCompare = (*dictionary)[i].substr(0, key_to_find.size());
        if (toCompare.compare(key_to_find) == 0) {
            (*matches)[j] = (*dictionary)[i];
            j++;
            if (j == matches->size()) break;
        }
    }
    for (int i = j; i < matches->size(); i++) {
        (*matches)[i] = "";
    }
}

int main(int argc, const char* argv[]) {
    using namespace ftxui;

    std::string currentString;
    std::vector<std::string> dictionary = {"grabs", "grace", "graced", "graceful", "gracefully", "gray"};
    std::vector<std::string> matchStrings (5, "");

    Component inputCurrentString = Input(&currentString, "Type here to search");

    auto component = Container::Vertical({
        inputCurrentString
    });

    auto renderer = Renderer(component, [&] {
        findMatches(&dictionary, currentString, &matchStrings);
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