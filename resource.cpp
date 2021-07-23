//resource.cpp

#include "resource.hpp"
#include <iostream>
#include <string>

//Default namespaces - Defination
namespace Choices
{
    const char* choices[] = {
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

namespace dflt
{
    const int n_choices = sizeof(Choices::choices) / sizeof(char *);
    const int sizeOfText = sizeof(Choices::text) / sizeof(char*);
    const int width{30};
    const int height{10};
}

Window::Window(int height, int width, int starty, int startx)
{
    initscr();
    clear();
    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */

    m_menuWin = newwin(height, width, starty, startx);
    keypad(m_menuWin, TRUE);
    mvprintw(0, (COLS - dflt::sizeOfText)/2, Choices::text);
    refresh();
}

void Window::PrintBody(int highlight, const char** tArray)
{
    int x, y;
    x = 2;
    y = 2;
    box(m_menuWin, 0, 0);
    for(int i = 0; i < dflt::n_choices; ++i)
    {	
        if(highlight == i + 1) /* High light the present choice */
        {	
            wattron(m_menuWin, A_REVERSE); 
            mvwprintw(m_menuWin, y, x, "%s", tArray[i]);
            wattroff(m_menuWin, A_REVERSE);
        }
        else
            mvwprintw(m_menuWin, y, x, "%s",tArray[i]);
        ++y;
    }
    wrefresh(m_menuWin);
}

int Window::PrintMenu(const char** tArray)
{
    int m_highlight = 1;
    int m_choice = 0;
    PrintBody(m_highlight, tArray);
    while(1)
    {	
        // c = wgetch(menu_win);
        switch(wgetch(m_menuWin))
        {	case KEY_UP:
                if(m_highlight == 1)
                    m_highlight = dflt::n_choices;
                else
                    --m_highlight;
                break;
            case KEY_DOWN:
                if(m_highlight == dflt::n_choices)
                    m_highlight = 1;
                else 
                    ++m_highlight;
                break;
            case 10:
                m_choice = m_highlight;
                break;
            default:
                // mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
        PrintBody(m_highlight, tArray);
        if(m_choice != 0)	/* User did a choice come out of the infinite loop */
            break;
    }
    return m_choice;
}

void Window::WriteMode()
{
    char text[100];
    echo();
    wgetstr(m_menuWin, text);


}

void Window::deleteFile()
{

}

void Window::openRecent()
{

}

Window::~Window()
{
    clrtoeol();
    refresh();
    endwin();
}