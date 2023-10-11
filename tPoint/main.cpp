#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <windows.h>
#include <math.h>

#define MAX_X 10
#define MAX_Y 10

class tPoint
{
private:
    int x;
    int y;
    int velocityX;
    int velocityY;

public:
    tPoint(int x, int y) : x(x), y(y), velocityX(0), velocityY(0) {}
    void draw()
    {
        std::cout << "Point: (" << x << ',' << y << ')' << std::endl;
        for (int i = 0; i < MAX_Y; i++)
        {
            for (int j = 0; j < MAX_X; j++)
            {
                if (j == x && i == y)
                {
                    std::cout << "o";
                }
                else
                {
                    std::cout << "_";
                }
            }
            std::cout << std::endl;
        }
        Sleep(10);
        system("cls");
    }
    void moveInStraightLineWithReflection()
    {
        // reflection
        if (x == MAX_X || x == 0)
        {
            velocityX = (-1) * velocityX;
        }
        if (y == MAX_Y || y == 0)
        {
            velocityY = (-1) * velocityY;
        }
        // move
        x += velocityX;
        y += velocityY;
    }
    void moveRandomlyWithReflection()
    {
        velocityX = rand() % 3 - 1;
        velocityY = rand() % 3 - 1;
        moveInStraightLineWithReflection();
    }
};

int main()
{
    std::srand(std::time(nullptr));
    // vector of random points
    std::vector<tPoint> points;
    for (int i = 0; i < 1; i++)
    {
        int x = std::rand() % MAX_X + 1;
        int y = std::rand() % MAX_Y + 1;
        tPoint point(x, y);
        points.push_back(point);
    }
    // drawing
    std::cout << std::endl;

    for (unsigned i = 0; i < points.size(); i++)
        points[i].moveRandomlyWithReflection();

    while (true)
    {
        for (unsigned i = 0; i < points.size(); i++)
        {
            points[i].draw();
            points[i].moveInStraightLineWithReflection();
        }
    }
    return 0;
}