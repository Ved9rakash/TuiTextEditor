#include "namespace.hpp"

#include <vector>
#include <string>

namespace Text
{
    const char* mainMenu[] = {
        "New    - Create new file.",
        "Open   - Open Existing file.",
        "Delete - Delete saved file.",
        "Recent - Recently opened files.",
        "Exit   - Leaves the Editor."
    };

    const char* test[] = {
        "vaibhav",
        "ruchi",
        "arjun"
    };

    const char* text = "Text Editor";
}

namespace Files
{
    std::vector<std::string> fileNames[10];

}

namespace dflt
{
    const int n_Text = sizeof(Text::mainMenu) / sizeof(char *);
    const int sizeOfText = sizeof(Text::text) / sizeof(char*);
    const int width{30};
    const int height{10};
}

namespace Files
{
    std::vector<std::string> fileNames[10];
}