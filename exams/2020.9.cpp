#include "stdio.h"

int (*funcp)(int, int);
int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main()
{
    int a = 20, b = 10;
    funcp = add;
    printf("%d\t", (*funcp)(a, b));
    funcp = sub;
    printf("%d\n", (*funcp)(a, b));
    return 0;
}