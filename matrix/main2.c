#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int *arr)
{
    printf("%d: ", arr[0]-1);
    for (int i = 1; i < arr[0]; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printMatrix(int **matrix, int size)
{
    printf("%d\n", size);
    for (int i = 0; i < size; i++)
    {
        print(matrix[i]);
    }
}

int *genRandArray(int size, int maxValue)
{
    int *arr = malloc(sizeof(int) * size);
    arr[0] = size;
    for (int i = 1; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}

int **genRandMatrix(int size, int maxValue)
{
    int **matrix = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++)
    {
        int size2 = rand() % 10 + 2;
        matrix[i] = malloc(sizeof(int) * size2);
        matrix[i] = genRandArray(size2, maxValue);
    }
    return matrix;
}

int main()
{
    srand(time(NULL));
    int maxValue = 100;
    int size = rand() % 10 + 2;
    int **matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);
    for(int i = 0; i < size;i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}