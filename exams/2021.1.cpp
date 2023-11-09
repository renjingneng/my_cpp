#include "stdio.h"

int main()
{
    int a[5];
    for (int i = 0; i < 5;)
        a[i] = i++ + 1;
    for (int j = 4; j >= 0;)
        printf("%d", *(a + j--));
    return 0;
}
