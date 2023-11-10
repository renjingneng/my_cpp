#include "stdio.h"

int fun()
{
    static int c = 1;
    printf("%d\t", c++);
    return 1;
}
int main()
{
    for (int i = 1; i < 4; i++)
        fun();
    return 0;
}