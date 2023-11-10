#include "stdio.h"

int main()
{
    FILE *fp;
    char src[] = "This-is-a-string", dst[50];
    fp = fopen("data.txt", "w");
    fprintf(fp, "%s", src);
    fclose(fp);
    fp = fopen("data.txt", "r");
    fscanf(fp, "%s", dst);
    printf("%s\n", dst);
    fclose(fp);
    return 0;
}
