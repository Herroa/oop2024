#include <iostream>
#include <cmath>

class tPoint
{
private:
    int x, y;
    int velocityX, velocityY;

public:
    tPoint(int x, int y) : x(x), y(y) {}
    void draw()
    {
        std::cout << "Point: (" << x << ',' << y << ')' << std::endl;
    }
};

class intercept : public tPoint
{
private:
    int x1, y1;
    int length;

public:
    intercept(int x0, int y0, int x1, int y1) : tPoint(x0, y0), x1(x1), y1(y1)
    {
        length = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    }
    int get_length() { return length; }
};

class triangle : public intercept
{
private:
    int x2, y2;

public:
    triangle(int x0, int y0, int x1, int y1, int x2, int y2) : intercept(x0, y0, x1, y1), x2(x2), y2(y2)
    {
    }
};

class rectangle : public triangle
{
private:
    int x3, y3;

public:
    rectangle(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) : triangle(x0, y0, x1, y1, x2, y2), x3(x3), y3(y3)
    {
    }
};

int main()
{
    intercept i(13, 9, 1, 4);
    triangle(13, 9, 1, 4, 10, 5);
    rectangle(13, 9, 1, 4, 10, 5, 10, 50);
    std::cout << i.get_length() << std::endl;
    return 0;
}
