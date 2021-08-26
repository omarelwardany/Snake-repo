#include "myheader.h"

int main()
{
    setup();
    while (!gameover)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        render();
        display();
        print("Your score is: " << snake.length);
        //Sleep(20);
        input();
        snake.move();
    }
    emptyline();
    emptyline();
    println("Game Over!");
    println("Press Enter to exit");
    cin.get();
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
                    gameover = true;
                }
            }
            else
            {
                if (fruithere)
                {
                    if (snakehere)
                    {
                        snake.length++;
                        buffer[i][j] = '+';
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
                    buffer[i][j] = '+';
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
            print(buffer[i][j]);
            print(' ');
        }
        emptyline();
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
                snake.vel.y = -1;
                snake.vel.x = 0;
                break;
            case 'a':
                snake.vel.y = 0;
                snake.vel.x = -1;
                break;
            case 's':
                snake.vel.y = 1;
                snake.vel.x = 0;
                break;
            case 'd':
                snake.vel.y = 0;
                snake.vel.x = 1;
        }
    }
}