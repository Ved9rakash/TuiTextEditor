#include <stdio.h>
#include <ncurses.h>
#include "resource.hpp"

int main()
{
    initscr();
    clear();
    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */

    //Creating a window and printing menu.
    Window test;
    test.PrintMenu(Choices::choices);
    

    clrtoeol();
    refresh();
    endwin();
    return 0;
}