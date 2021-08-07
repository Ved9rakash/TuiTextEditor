//namespace.cpp

#include "../include/namespace.hpp"

#include <vector>
#include <string>
#include <array>

namespace Text
{
    std::vector<std::string> mainMenu = {
        "New    - Create new file.",
        "Open   - Open Existing file.",
        "Delete - Delete saved file.",
        "Exit   - Leaves the Editor."
    };

    //Editor main title
    const char* textEditor = "Text Editor";
}

//Default variable namespace
namespace dflt
{
    const int n_mainMenu = Text::mainMenu.size();
    const int n_textEditor = sizeof(Text::textEditor) / sizeof(char*);
    const int width{30};
    const int height{10};
}

//File names to be stored inside vector and updated.
namespace Files
{
    std::vector<std::string> fileNames;
}