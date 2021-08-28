#include "myheader.h"

int main()
{
    println("Please choose your game mode, (E)asy or (H)ard?");
    do
    {
        int key = _getch();
        if (key == 'e')
        {
            gamemode = EASY;
        }
        else if (key == 'h')
        {
            gamemode = HARD;
        }
        
    } while (gamemode != EASY and gamemode != HARD);
    
    bool firstloop;
    start:
    setup();
    setCursor(0, false);
    firstloop = true;
    while (not gameover)
    {
        setCursor(0, false);
        SetConsoleCursorPosition(StdHandle, {0, 0}); //return console cursor to origin
        render(); //build up the buffer
        display(); //display the buffer
        print("Your score is: " << snake.length);
        if (firstloop)
        {
            for (int i = 0; i < 5; i++)
            {
                println("                                                             ");
                firstloop = false;
            }
        }
        Sleep(30);
        input(); //get key pressed
        snake.move(); //move the snake by 1 unit of distance
    }
    newline;
    newline;
    system("color 0C");
    println("Game Over!");
    println("(R)etry or (C)ontinue or (E)xit");
    Sleep(1000);
    end:
    switch(_getch())
    {
        case 'r':
            snake.length = 0;
        case 'c':
            goto start;
        case 'e':
            return 0;
        default:
            goto end;
    }
    setCursor(10, true);
    system("color 07");
}

