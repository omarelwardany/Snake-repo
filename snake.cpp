#include "myheader.h"

int main()
{
    println("Please choose a difficulty, (E)asy or (H)ard?");
    newline;
    println("(E)asy: You only die from biting yourself, \n        but you can teleport through walls");
    newline;
    println("(H)ard: You can also die when you hit a wall");
    do
    {
        int key = _getch();
        if (key == 'e')
        {
            difficulty = EASY;
        }
        else if (key == 'h')
        {
            difficulty = HARD;
        }
    } while (difficulty != EASY and difficulty != HARD);
    
    bool firstloop;
    start:
    setup();
    firstloop = true;
    while (not gameover)
    {
        SetConsoleCursorPosition(StdHandle, {0, 0}); //return console cursor to origin
        setCursor(0, false);
        render(); //build up the buffer
        display(); //display the buffer
        print("Your score is: " << snake.length);
        if (firstloop)
        {
            for (int i = 0; i < 5; i++)
            {
                println("                                                             ");
            }
                firstloop = false;
        }
        Sleep(30);
        input(); //get key pressed
        snake.move(); //move the snake by 1 unit of distance
    }
    newline;
    newline;
    system("color 0C");
    println("Game Over!");
    newline;
    println("(R)etry: Will restart the game from zero length");
    println("(C)ontinue: Will restart the game at the current length");
    println("(Q)uit: Will close the game");
    end:
    switch(_getch())
    {
        case 'r':
            snake.length = 0;
        case 'c':
            goto start;
        case 'q':
            return 0;
        default:
            goto end;
    }
    setCursor(10, true);
    system("color 07");
}

