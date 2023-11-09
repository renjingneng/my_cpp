#include "stdio.h"
int main()
{

    int a[10];
    for (int i = 0; i < 10; i++) a[i] = i;
    printf("%d\n", *(a + 2));
    printf("%d", (a + 2)[3]);//0 1 2 3 4
    return 0;
}