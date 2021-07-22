#ifndef RESOURSE_HPP
#define RESOURSE_HPP

#include <ncurses.h>

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
    //int m_highlight{1};
    //int m_choice{0};
    int m_char;
    
public:
    Window();

    void PrintBody(int highlight, const char** tArray);

    void PrintMenu(const char** tArray);
};


#endif