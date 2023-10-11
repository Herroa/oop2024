#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>

void gen_matrix(int **pp, int n)
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pp[i][j] = x++;
            std::cout << std::setw(3) << pp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void print(int *p, int n)
{
    for (int i = 0; i < n * n; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}

void left_diag(int **pp, int *d, int n)
{
    int index = 0, rows, cols;
    for (int diagonal = 0; diagonal < n; diagonal++)
    {
        rows = 0;
        cols = diagonal;
        while (rows < n && cols >= 0)
        {
            d[index++] = pp[rows++][cols--];
        }
    }

    for (int diagonal = 1; diagonal < n; diagonal++)
    {
        rows = diagonal;
        cols = n - 1;
        while (rows < n && cols >= 0)
        {
            d[index++] = pp[rows++][cols--];
        }
    }
}

void right_diag(int **pp, int *d, int n)
{
    int index = 0, rows, cols;
    for (int diagonal = n - 1; diagonal >= 0; diagonal--)
    {
        rows = 0;
        cols = diagonal;

        while (rows < n && cols < n)
        {
            d[index++] = pp[rows++][cols++];
        }
    }

    for (int diagonal = 1; diagonal < n; diagonal++)
    {
        rows = diagonal;
        cols = 0;
        while (rows < n && cols < n)
        {
            d[index++] = pp[rows++][cols++];
        }
    }
}

void spiral_center(int **pp, int *d, int n)
{
    int centerX = n / 2;
    int centerY = n / 2;
    int currentX = centerX;
    int currentY = centerY;
    int direction = 0;
    int step = 1;
    int stepsCount = 0;

    if (n % 2 == 0)
    {
        currentX -= 1;
        currentY -= 1;
    }
    for (int i = 0; i < n * n; ++i)
    {
        d[i] = pp[currentY][currentX];

        if (stepsCount == step)
        {
            stepsCount = 0;
            direction = (direction + 1) % 4;
            if (direction % 2 == 0)
            {
                step++;
            }
        }

        switch (direction)
        {
        case 0:
            currentX++;
            break;
        case 1:
            currentY++;
            break;
        case 2:
            currentX--;
            break;
        case 3:
            currentY--;
            break;
        }

        stepsCount++;
    }
}

void spiral_left(int **pp, int *d, int n)
{
    int index = 0, rows = 0, cols = 0, loop = 0;

    for (int size = n - 1; size >= 0; size = size - 2)
    {
        for (int i = 0; i < size; i++)
        {
            d[index++] = pp[rows][cols++];
        }
        for (int i = 0; i < size; i++)
        {
            d[index++] = pp[rows++][cols];
        }
        for (int i = 0; i < size; i++)
        {
            d[index++] = pp[rows][cols--];
        }
        for (int i = 0; i < size; i++)
        {
            d[index++] = pp[rows--][cols];
        }
        loop++;
        rows = loop;
        cols = loop;
    }
}

int main()
{
    std::srand(std::time(nullptr));
    int n = 6;
    int **pp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        pp[i] = new int[n];
    }
    gen_matrix(pp, n);

    int *d = new int[n * n];

    left_diag(pp, d, n);
    print(d, n);
    right_diag(pp, d, n);
    print(d, n);
    spiral_left(pp, d, n);
    print(d, n);
    spiral_center(pp, d, n);
    print(d, n);
    return 0;
}