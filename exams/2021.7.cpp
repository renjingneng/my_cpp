#include "stdio.h"
#include "stdlib.h"
int fun(char *s)
{
    if (*(++s))
        fun(s);
    printf("%c", *(s - 1));
    return 0;
}

int main()
{
    char *str = "dcbaTzyx";//xyzTabcd
    fun(str);
    return 0;
}