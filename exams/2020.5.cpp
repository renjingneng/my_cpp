#include "stdio.h"

int fun(int a)
{
    int product = 1;
    if (a == 0)
        return product;
    else
        return a * fun(a - 1);
}

int main()
{
    printf("%d\n", fun(5));
    return 0;
}