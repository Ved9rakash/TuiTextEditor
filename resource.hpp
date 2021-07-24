//resource.hpp

#ifndef RESOURSE_HPP
#define RESOURSE_HPP

#include <ncurses.h>
#include <vector>
#include <string>

class Window
{
private:
    WINDOW *m_menuWin;
    
public:
    Window(int height, int width, int starty, int startx);
    void PrintBody(int highlight, std::vector<std::string> text);
    int PrintMenu(std::vector<std::string> text);
    void PrintBodyV(int highlight, std::vector<std::string> text);
    void PrintMenuV(std::vector<std::string>& test);
    void WriteMode();
    void deleteFile();
    void openRecent();

    ~Window();
};


#endif