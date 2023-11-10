#include "stdio.h"

int main()
{

    char s[] = "TSUWS", *p = s;
    int i = 4;
    while (i >= 0)
    {
        printf("%c", *(p + i));
        i--;
    }

    return 0;
}
