#include <string>
#include <vector>
#include "GenericCompleter.h"

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border

ftxui::Component Window(std::string title, ftxui::Component component) {
    return ftxui::Renderer(component, [component, title] {
        return ftxui::window(ftxui::text(title), component->Render()) | ftxui::flex;
    });
}

int main(int argc, const char* argv[]) {
    int menuSelected[] = {0, 0};
    const int maxQuantityToMatch = 6;
    std::string currentString;
    std::vector<std::string> dictionary = {"grabs", "grace", "graced", "graceful", "gracefully", "gray"};
    std::vector<std::string> matchStrings (maxQuantityToMatch, "");
    std::vector<std::vector<std::string>> menuEntries = {{"FST", "Red Black Tree", "Levans"}, {"1", "2", "3", "4", "5", "6"}};

    // Instantiate completers
    GenericCompleter completer(dictionary, matchStrings, 1, maxQuantityToMatch);

    // GUI components

    ftxui::Component inputCurrentString = ftxui::Input(&currentString, "Type here to search");
    auto component = ftxui::Container::Vertical({inputCurrentString});
    
    auto globalMenu = ftxui::Container::Vertical(
        {
            Window("Select the autocomplete", ftxui::Menu(&menuEntries[0], &menuSelected[0])),
            Window("Select the max number of strings for the autocomplete", ftxui::Menu(&menuEntries[1], &menuSelected[1]))
        }
    );
 
    auto renderer = ftxui::Renderer(component, [&] {
        // Select the right completer and set the number os strings to search for
        completer.selectCompleter(menuSelected[0]);
        completer.setMatchesNumber(menuSelected[1] + 1);

        // Generate autocomplete strings
        completer.autoComplete(currentString);

        return window(ftxui::text("Content"), ftxui::vbox(
            {
                hbox(ftxui::text(" Search : "), inputCurrentString->Render()),
                ftxui::separator(),
                ftxui::hbox(ftxui::text(" "), ftxui::text(matchStrings[0])),
                ftxui::hbox(ftxui::text(" "), ftxui::text(matchStrings[1])),
                ftxui::hbox(ftxui::text(" "), ftxui::text(matchStrings[2])),
                ftxui::hbox(ftxui::text(" "), ftxui::text(matchStrings[3])),
                ftxui::hbox(ftxui::text(" "), ftxui::text(matchStrings[4])),
                ftxui::hbox(ftxui::text(" "), ftxui::text(matchStrings[5])),
            }
        )) | ftxui::flex;
    });
 
    auto global = ftxui::Container::Horizontal({
        globalMenu,
        renderer,
    });

    // Display
 
    auto screen = ftxui::ScreenInteractive::TerminalOutput();
    screen.Loop(global);
    return 0;
}