#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int i, j;
    int a[8];
    srand((int)time(0));
    a[0] = rand() % 8;
    for (i = 1; i < 8; i++)
    {
        a[i] = rand() % 8;
        for (j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                i--;
            }
        }
    }
    for (i = 0; i < 8; i++)
    {
        printf("%d\n", a[i]);
    }
}