#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <vector>
#include <string>

//namspace.hpp

//Text and menu used inside the program
namespace Text
{
    extern std::vector<std::string> mainMenu;
    extern const char* textEditor;
}

//Default variables
namespace dflt
{
    extern const int n_mainMenu;
    extern const int n_textEditor;
    extern const int width;
    extern const int height;
}

//Files used inside the program
namespace Files
{
    extern std::vector<std::string> fileNames;
}

#endif