#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
#define DIM 35
#define print(x) cout << x
#define println(x) cout << x << endl
#define emptyline() cout << endl
#define and &&
#define or ||
#define not !
#define snakehere i == snake.pos.x and j == snake.pos.y
#define fruithere i == fruit.pos.x and j == fruit.pos.y
#define newfruit fruit.pos.x = rand() % (DIM - 5); fruit.pos.y = rand() % (DIM - 5)


struct Position
{
    int x, y;
};

struct Velocity
{
    int x, y;
};

class Fruit
{
    public:
    Position pos;
} fruit;

class Snake
{
    public:
    Position pos;
    Velocity vel;
    int length;

    void move()
    {
        pos.x += vel.x;
        pos.y += vel.y;
    }
} snake;

bool gameover;
char buffer[DIM][DIM];
int points[DIM][DIM];

void setup();
void render();
void display();
void input();
