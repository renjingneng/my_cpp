#include "stdio.h"
#include "stdlib.h"
int main()
{
    char s[][8] = {"welcome", "to", "swust"};
    char *res = (char *)malloc(sizeof(char) * 40);
    char *p = res;
    for (int i = 0; i < 3; i++)
    {
        char *tmp = s[i];
        while (*tmp)
            *p++ = *tmp++;
    }
    *p = '\0';
    printf("%s", res);
    free(res);
    return 0;
}