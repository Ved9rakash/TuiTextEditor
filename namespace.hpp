#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <vector>
#include <string>

namespace Text
{
    extern std::vector<std::string> mainMenu;
    extern std::vector<std::string> test;
    extern const char* textEditor;
}

namespace dflt
{
    extern const int n_mainMenu;
    extern const int n_textEditor;
    extern const int width;
    extern const int height;
}

namespace Files
{
    extern std::vector<std::string> fileNames;
}

#endif