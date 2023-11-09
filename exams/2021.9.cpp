#include "stdio.h"
#include "stdlib.h"

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int aver(int a, int b) { return (a + b) / 2; }
int main()
{
    int a = 50, b = 80;
    int (*funcp[3])(int, int);
    funcp[0] = max;
    funcp[1] = min;
    funcp[2] = aver;
    for (int i = 0; i < 3; i++)
        printf("%d\t", (*funcp[i])(a, b));
    return 0;
}