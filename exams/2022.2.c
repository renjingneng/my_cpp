#include "stdio.h"
#include "stdlib.h"

void fun(char *s1, const char *s2)
{
    if (!*s2)
    {
        *s1 = '\0';
        return;
    }
    *s1++ = *s2++;
    fun(s1, s2);
}

int main()
{
    char s[] = "Good Luck!";
    char *d = (char *)malloc(sizeof(s));
    fun(d, s);
    printf("%s\n", d);
    free(d);
    return 0;
}