#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
#define DIM 25
#define print(x) cout << x
#define println(x) cout << x << endl
#define newline cout << endl
#define and &&
#define or ||
#define not !
#define snakehere i == snake.pos.x and j == snake.pos.y
#define fruithere i == fruit.pos.x and j == fruit.pos.y
#define newfruit fruit.pos.x = rand() % (DIM - 5); fruit.pos.y = rand() % (DIM - 5)
#define EASY 1
#define HARD 2
#include "classes.h"

bool gameover;
char buffer[DIM][DIM];
int points[DIM][DIM];
int gamemode = 0;

HANDLE StdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
void setCursor(int size, bool visible)
{
   CONSOLE_CURSOR_INFO info;
   info.dwSize = size;
   info.bVisible = visible;
   SetConsoleCursorInfo(StdHandle, &info);
}

void textColor(int color)
{
    SetConsoleTextAttribute(StdHandle, color);
}

void setup()
{
    snake.pos.x = DIM / 2;
    snake.pos.y = DIM / 2;
    snake.vel.x = 1;
    snake.vel.y = 0;
    do
    {
        newfruit;
    } while (fruit.pos.x < 4 or fruit.pos.y < 4);
    system("color 0F");
    
    gameover = false;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            points[i][j] = 0;
        }
    }
    srand((unsigned) 20);
}

void render()
{
    for (int j = 0; j < DIM; j++)
    {
        for (int i = 0; i < DIM; i++)
        {
            if (i == 0 or i == DIM - 1 or j == 0 or j == DIM - 1)
            {
                buffer[i][j] = '#';
                if (snakehere)
                {
                    if (gamemode == HARD)
                    {
                        gameover = true;
                    }
                    else
                    {
                        if (i == 0)
                            snake.pos.x = DIM - 2;
                        if (i == DIM - 1)
                            snake.pos.x = 0;
                        if (j == 0)
                            snake.pos.y = DIM - 2;
                        if (j == DIM - 1)
                            snake.pos.y = 0;
                    }
                }
            }
            else
            {
                if (fruithere)
                {
                    if (snakehere)
                    {
                        snake.length++;
                        buffer[i][j] = 'O';
                        points[i][j] = snake.length;
                        do
                        {
                            newfruit;
                        } while (fruit.pos.x < 4 or fruit.pos.y < 4);
                    }
                    else
                        buffer[i][j] = '@';
                }
                else if (points[i][j])
                {
                    buffer[i][j] = '+';
                    points[i][j]--;
                    if (snakehere)
                        gameover = true;
                }
                else if (snakehere)
                {
                    buffer[i][j] = 'O';
                    points[i][j] = snake.length;
                }
                else
                    buffer[i][j] = ' ';
            }
        }
    }
}

void display()
{
    for (int j = 0; j < DIM; j++)
    {
        for (int i = 0; i < DIM; i++)
        {
            if (buffer[i][j] == '+' or buffer[i][j] == 'O')
                textColor(10);
            else if (buffer[i][j] == '@')
                textColor(12);
            print(buffer[i][j]);
            print(' ');
            textColor(15);
        }
        newline;
    }
}

void input()
{
    if (_kbhit())
    {
        int key = _getch();
        switch(key)
        {
            case 'w':
            if (snake.vel.y != 1)
            {
                snake.vel.y = -1;
                snake.vel.x = 0;
            }
            break;
                
            case 'a':
            if (snake.vel.x != 1)
            {
                snake.vel.y = 0;
                snake.vel.x = -1;
            }
            break;
            case 's':
            if (snake.vel.y != -1)
            {
                snake.vel.y = 1;
                snake.vel.x = 0;
            }
                break;
            case 'd':
            if (snake.vel.x != -1)
            {
                snake.vel.y = 0;
                snake.vel.x = 1;
            }
        }
    }
}
