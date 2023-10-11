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

int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    print(arr);
    free(arr);

    return 0;
}