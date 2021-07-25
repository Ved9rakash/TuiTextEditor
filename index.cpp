//index.cpp

/*
Author  : ved9rakash
Version : 1.0.0
Status  : Not complete

This is a ncurses based TUI text editor made in c++(Both using modern
and legacy code). A simple text editor which does some regular tasks like 
creating new files, deleting, etc.
*/

/*
Including the additional created header files.
Unfortunately windows don't have ncurses.h header and it's 
libraries, so it's a unix system project. To make it work
it on windows, see - https://www.msys2.org/ and add 
include directory in c_cpp_properties.json - vscode ( which
i'm currently using).
*/

#include "resource.hpp"
#include "namespace.hpp"

#include <ncurses.h>

#include <iostream>
#include <stdio.h>
#include <thread>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    //Creating a window and printing menu.
    //system("ls");

    //Variable dependent infinite loop.
    bool EXIT = true;
    while(EXIT)
    {
        //c++17 switch statemtment, menu window is main window.
        switch (Window menuWindow(9, 50, 2, 2); menuWindow.PrintMenu(Text::mainMenu))
        {
            case 1:
            //Creates new write-text window.
            {
                Window newFileWindow(LINES-2, COLS-2, 1, 1);
                newFileWindow.NewFile();
                //Code for file writing
            }
                break;

            case 2:
            //Creates open-files windows
                {
                    Window openFileWindow(20, 50, 2, 2);
                    openFileWindow.PrintMenu(Files::fileNames);
                    //Code for opening the files
                }
                break;

            case 3:
            //Creates open-files window and let user to delete specific file.
            {
                Window deleteFileWindow(20, 50, 2, 2);
                deleteFileWindow.deleteFile();
                //code for opening the files and then deleting it.
                break;
            }
            case 4:
            //Creates open-recent windows to display latest 5 opened files.
            {
                Window openRecentWindow(20, 50, 2, 2);
                openRecentWindow.openRecent();
                //code for opening the recent files.
                break;
            }
            case 5:
                //Exits the window
                //Exits the loop and breaks
                EXIT = false;
                break;
        }
    }
    //Implicity menuWindow destructor called from switch and end of program.
    return 0;
}