//resource.cpp

#include "resource.hpp"
#include "namespace.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>


/*
    Window Constructor, Takes 4 parameter,
    height and width to define working window dimensions 
    and starty and startx to define where to start in working
    window.
*/
Window::Window(int height, int width, int starty, int startx)
{
    /*
        Initialize the screen. Clearing screen.
        Setting the input to noecho() with cbreak.
    */
    initscr();
    clear();
    noecho();
    cbreak();	

    m_menuWin = newwin(height, width, starty, startx);
    keypad(m_menuWin, TRUE);

    //For every window created, The title TextEditor will be added at top.
    mvprintw(0, (COLS - dflt::n_textEditor)/2, Text::textEditor);
    refresh();
}

//Printing the Menu.
void Window::PrintBody(int highlight, std::vector<std::string> text)
{
    /*
        This Function will take the vector as string and print it with 
        different attributes given in ncurses.h library.
        xMargin = Distance from x axis
        yMargin = Distance from y axis
        Where the vector values to be printed.
    */
    int xMargin, yMargin;
    xMargin = 2;
    yMargin = 2;
    box(m_menuWin, 0, 0);
    for(int i = 0; i < dflt::n_mainMenu; ++i)
    {	
        if(highlight == i + 1) /* High light the present choice */
        {	
            wattron(m_menuWin, A_REVERSE); 
            mvwprintw(m_menuWin, yMargin, xMargin, "%s", text[i].c_str());
            wattroff(m_menuWin, A_REVERSE);
        }
        else
            mvwprintw(m_menuWin, yMargin, xMargin, "%s",text[i].c_str());
        ++yMargin;
    }
    wrefresh(m_menuWin);
}

int Window::PrintMenu(std::vector<std::string> text)
{
    /*
        Take the input(Keyboard) from user and pass it to PrintBody()
        to print the values with attributes.
    */
    int m_highlight = 1;
    int m_choice = 0;
    PrintBody(m_highlight, text);

    while(m_choice == 0)
    {	
        switch(wgetch(m_menuWin))
        {	case KEY_UP:
                if(m_highlight == 1)
                    m_highlight = dflt::n_mainMenu;
                else
                    --m_highlight;
                break;
            case KEY_DOWN:
                if(m_highlight == dflt::n_mainMenu)
                    m_highlight = 1;
                else 
                    ++m_highlight;
                break;
            case 10:
                m_choice = m_highlight;
                break;
            case 120:
                //Delete the value and update it.
            default:
                // mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
        PrintBody(m_highlight, text);
    }
    return m_choice;
}

void Window::PrintBodyV(int highlight, std::vector<std::string> test)
{
    int x, y;
    x = 2;
    y = 2;
    box(m_menuWin, 0, 0);
    for(int i = 0; i < test.size(); ++i)
    {	
        if(highlight == i + 1) /* High light the present choice */
        {	
            wattron(m_menuWin, A_REVERSE); 
            mvwprintw(m_menuWin, y, x, "%s", test[i].c_str());
            wattroff(m_menuWin, A_REVERSE);
        }
        else
            mvwprintw(m_menuWin, y, x, "%s",test[i].c_str());
        ++y;
    }
    wrefresh(m_menuWin);
}

void Window::PrintMenuV(std::vector<std::string>& text, int flag )
{
    int m_highlight = 1;
    int m_choice = 0;
    PrintBodyV(m_highlight, text);

    /*
        If flag is 0 i.e only for getting menu and displaying it.
    */
    if (flag == 0)
    {
        while(m_choice == 0)
        {	
            // c = wgetch(menu_win);
            switch(wgetch(m_menuWin))
            {	case KEY_UP:
                    if(m_highlight == 1)
                        m_highlight = text.size();
                    else
                        --m_highlight;
                    break;
                case KEY_DOWN:
                    if(m_highlight == text.size())
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
        PrintBodyV(m_highlight, text);
        }
    }
    /*
        If flag is 1 i.e only for getting menu and displaying it and asking user to press X.
    */
    else if(flag ==1)
    {
        while(m_choice == 0)
        {
            switch(wgetch(m_menuWin))
            {	case KEY_UP:
                    if(m_highlight == 1)
                        m_highlight = text.size();
                    else
                        --m_highlight;
                    break;
                case KEY_DOWN:
                    if(m_highlight == text.size())
                        m_highlight = 1;
                    else 
                        ++m_highlight;
                    break;
                case 10:
                    break;
                case 120:
                    m_choice = m_highlight;
                    //Open the respected file in append mode.
                    break;
                default:
                    // mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                    refresh();
                    break;
            }
        PrintBodyV(m_highlight, text);
        }
    }
}

void Window::WriteMode(std::string fileName)
{
    //Open file "fileName" and append the data.
    //If the data 

}

void Window::NewFile()
{
    char fileN[20];
    echo();


    //File name.
    mvprintw(3, 0, "Enter the file name:\n");
    getstr(fileN);
    Files::fileNames.push_back(fileN);
}

void Window::deleteFile()
{
    mvprintw(5, 0, "Press x which file to delete.");

    FILE *fp = popen("ls", "r");
    char buf[30];
    while (fgets(buf, 30, fp))
    {
        Files::fileNames.push_back(buf);
    }
    PrintMenuV(Files::fileNames, 1);
}

void Window::openRecent()
{
    mvprintw(5, 0, "Press 'Enter' to open file.");
    //Prints the file.
    PrintMenuV(Files::fileNames);

}

Window::~Window()
{
    clrtoeol();
    refresh();
    endwin();
}