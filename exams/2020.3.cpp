#include "stdio.h"

int swap(int *p1, int *p2)
{
    int tmp = 0;
    tmp = *p2;
    *p2 = *p1;
    *p1 = tmp;
    return 1;
}
int main()
{
    int a = 123, b = 321;
    swap(&a, &b);
    printf("%d\t%d", a, b);
    return 0;
}