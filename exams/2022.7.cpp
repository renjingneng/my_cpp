#include "stdio.h"

int cnt(char *s)
{
    int i = 0, c = 0;
    if (s)
    
        while (*(s + i))
        {
            if (s[i] == 'B' || *(s + i) == 'b')
            
                c++;
            
            i++;
        }
    
    return c;
}

int main()
{
    int c = 0;
    char s[][6] = {"book", "BBS", "bee", "table"};

    for (int i = 0; i < sizeof(s) / sizeof(s[0]);)
    {
        c += cnt(*(s + i++));
    }
    printf("%d\n", c);
    return 0;
}