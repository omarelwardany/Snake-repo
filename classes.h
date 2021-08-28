struct Vector
{
    int x, y;
};

class Fruit
{
    public:
    Vector pos;
} fruit;

class Snake
{
    public:
    Vector pos;
    Vector vel;
    int length;

    void move()
    {
        pos.x += vel.x;
        pos.y += vel.y;
    }
} snake;