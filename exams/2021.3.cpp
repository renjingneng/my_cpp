#include "stdio.h"
int main()
{

    int a[10][10];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            a[i][j] = (i + 1) * (j + 1);
    printf("%d", (*(a + 2))[6]);
    return 0;
}