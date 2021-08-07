//resource.cpp

#include "../include/resource.hpp"
#include "../include/namespace.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>
#include <ios>
#include <experimental/filesystem>
#include <algorithm>


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
   //Getting the file inside the vector.
    FILE *fp = popen("ls", "r");
    char buf[30];
    Files::fileNames.clear();
    while (fgets(buf, 30, fp))
    {
        Files::fileNames.push_back(buf);
    }
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
    for(auto i = 0; i < static_cast<int>(text.size()); ++i)
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

int Window::PrintMenu(std::vector<std::string> text, int flag /*=0*/)
{
    /*
        Take the input(Keyboard) from user and pass it to PrintBody()
        to print the values with attributes.
    */
    long unsigned int m_highlight = 1;
    int m_choice = 0;
    PrintBody(m_highlight, text);

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
        PrintBody(m_highlight, text);
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
        PrintBody(m_highlight, text);
        }
    }
    return m_choice;
}

void Window::WriteMode(std::string fileName)
{
    //Open file "fileName" in append mode.
    //If it's present
    echo();
    mvprintw(5, 0, "\n");
    if (std::experimental::filesystem::exists(fileName))
    {
        std::ofstream file;
        file.open(fileName, std::ios_base::ate);
        char text[1024];
        getstr(text);
        file << text << '\n';
        file.close();
    }
    else
    {
        std::string cmd = "touch " + fileName;
        //If file doesnt exists.
        system(cmd.c_str());
        std::fstream file;
        file.open(fileName, std::ios::out);
        char text[1024];
        getstr(text);
        file << text << '\n';
        file.close();
        Files::fileNames.push_back(fileName);
    }
    
}

void Window::NewFile()
{
    //New file is complete OK
    char fileName[20];
    echo();
    //File name.
    mvprintw(3, 0, "Enter the file name:\n");
    getstr(fileName);
    WriteMode(fileName);
}

void Window::openFile()
{
    int selected = PrintMenu(Files::fileNames);
    Window Test(LINES-2, COLS-2, 1, 1);
    Test.WriteMode(Files::fileNames[selected - 1]);
}

void Window::deleteFile()
{
    //Delete Ok.
    std::string cmd, fileName;
    int selected = PrintMenu(Files::fileNames, 1);
    fileName = Files::fileNames[selected - 1];
    cmd = "rm -rf " + fileName;
    system(cmd.c_str());
    Files::fileNames.erase(Files::fileNames.begin() + selected - 1);
}

Window::~Window()
{
    clrtoeol();
    refresh();
    endwin();
}