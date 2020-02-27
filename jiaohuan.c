#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    srand((int)time(0));
    int num;
    int a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int i = 7; i >= 0; i--)
    {
        num = rand() % 8;
        swap(&a[i],&a[num]);
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d",a[i]);
    }
    
}