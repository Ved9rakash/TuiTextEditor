//resource.cpp

#include "resource.hpp"
#include "namespace.hpp"

#include <iostream>
#include <string>
#include <vector>


Window::Window(int height, int width, int starty, int startx)
{
    initscr();
    clear();
    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */

    m_menuWin = newwin(height, width, starty, startx);
    keypad(m_menuWin, TRUE);
    mvprintw(0, (COLS - dflt::sizeOfText)/2, Text::text);
    refresh();
}

void Window::PrintBody(int highlight, const char** tArray)
{
    int x, y;
    x = 2;
    y = 2;
    box(m_menuWin, 0, 0);
    for(int i = 0; i < dflt::n_Text; ++i)
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
                    m_highlight = dflt::n_Text;
                else
                    --m_highlight;
                break;
            case KEY_DOWN:
                if(m_highlight == dflt::n_Text)
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
    std::string text;
    
    // wgetstr(m_menuWin, text);
    // wgetnstr();


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