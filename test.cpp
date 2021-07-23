#include "resource.hpp"

#include <iostream>
#include <stdio.h>
#include <ncurses.h>
#include <thread>
#include <stdlib.h>

int main()
{
    int exit{0};
    //Creating a window and printing menu.
    //system("ls");

    while(exit == 0)
    {
        switch (Window test(9, 50, 2, 2); test.PrintMenu(Choices::choices))
        {
            case 1:{
                
                Window test2(50, 20, 10, 10);
                test2.PrintMenu(Choices::test);
            }
                break;
            
            case 2:

                break;

            case 3:

                break;

            case 4:

                break;
            
            case 5:
                //Exits the loop and breaks
                exit = 1;
                break;
        }
    }
    return 0;
}