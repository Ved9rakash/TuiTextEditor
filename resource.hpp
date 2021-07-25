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
    void PrintMenuV(std::vector<std::string>& test, int flag = 0);
    void WriteMode();       //Creates new file and edits it
    void deleteFile();      //Deletes current files and updates it.
    void openRecent();      //Open last 5 recent files.

    ~Window();
};


#endif