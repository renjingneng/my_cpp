#include "stdio.h"

int main()
{
    char s[6][10] = {"Happy", "new", "year"}, *p;
    for (int i = 0; i < 4; i++)
    {
        p = s[i];
        printf("%s\t", p);
    }
    return 0;
}
