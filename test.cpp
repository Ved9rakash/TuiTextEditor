#include <stdio.h>
#include <ncurses.h>
#include "resource.hpp"
#include <iostream>

int main()
{
    //Creating a window and printing menu.
    switch (Window test(10, 50); test.PrintMenu(Choices::choices))
    {
        case 1:
            Window test2(50, 20);
            test2.PrintMenu(Choices::test);
            break;
    }
    return 0;
}