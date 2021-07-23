//resource.hpp

#ifndef RESOURSE_HPP
#define RESOURSE_HPP

#include <ncurses.h>

//Default namespaces - Declaration
namespace Choices
{
    extern const char* choices[];
    extern const char* test[];
    extern const char* text;
}

namespace dflt
{
    extern const int n_choices;
    extern const int sizeOfText;
    extern const int width;
    extern const int height;
}

class Window
{
private:
    WINDOW *m_menuWin;
    
public:
    Window(int height, int width, int starty, int startx);
    void PrintBody(int highlight, const char** tArray);
    int PrintMenu(const char** tArray);
    void WriteMode();
    void deleteFile();
    void openRecent();

    ~Window();
};


#endif