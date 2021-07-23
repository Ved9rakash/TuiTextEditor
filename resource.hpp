//resource.hpp

#ifndef RESOURSE_HPP
#define RESOURSE_HPP

#include <ncurses.h>

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