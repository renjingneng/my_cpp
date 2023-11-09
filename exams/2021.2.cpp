#include "stdio.h"

int fun(char *str1, char *str2)
{
    while ((*str1++ == *str2++) && (*str1))
        ;
    if ((*str1 == *str2) && (!*str1))
        return 0;
    else if ((*str1) && (!*str2))
        return -1;
    else if ((*str2) && (!*str1))
        return 1;
    else
        return (*str1 > *str2) ? -1 : 1;
}
int main()
{
    char sl[] = "pytorch";
    char s2[] = "python";
    printf("%d\n", fun(sl, s2));
    return 0;
}