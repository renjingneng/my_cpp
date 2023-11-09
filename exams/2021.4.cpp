#include "stdio.h"
int fun(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
    return a / b;
}
int main()
{
    static int a = 222, b = 666;
    printf("%d\n", fun(a, b) * a);
    return 0;
}