#include "stdio.h"

int *(*funcp1[2])(int *, int *, int *);
int (*funcp2[2])(int *, int *);

int *max(int *a, int *b, int *c)
{
    int *x = *a > *b ? a : b;
    return *x > *c ? x : c;
}
int *min(int *a, int *b, int *c)
{
    int *x = *a < *b ? a : b;
    return *x < *c ? x : c;
}
int mul(int *a, int *b)
{
    return *a * *b;
}
int div(int *a, int *b)
{
    return *b ? *a / (*b) : -1;
}

int main()
{
    int a = 10, b = 20, c = 30, result = 0;
    funcp1[0] = max;
    funcp1[1] = min;
    funcp2[0] = mul;
    funcp2[1] = div;
    for (int j = 0; j < 2;)
    {
        result += (*funcp2[j++])((*funcp1[0])(&a, &b, &c), (*funcp1[1])(&a, &b, &c));
    }
    printf("%d\n", result);
    return 1;
}