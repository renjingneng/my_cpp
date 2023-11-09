#include "stdio.h"
#include "stdlib.h"
int fun1(char *s)
{
    int i = 0;
    if (s)
        while (s[++i])//aa
            ;
    return i;
}
int fun2(int c, char *s[])
{
    int sum = 0;
    for (int i = 0; i < c; i++)
        sum += fun1(s[i]);
    return sum;
}

int main()
{
    char s[][8] = {"aa",
                   "bbbb",
                   "cc", 
                   "ddd"};
    char *p[4];
    for (int i = 0; i < 4; i++)
        p[i] = s[i];
    printf("%d", fun2(4, p));
    return 0;
}