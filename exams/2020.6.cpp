#include "stdio.h"

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i = 0, sum = 0;
    while (i < 10)
    {
        if (i % 2)
        {
            sum = sum + a[i];
        }

        i++;
    }

    printf("%d\n", sum);
    return 0;
}