// 1-1.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("tmp.csv", "w+");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "ID,Name,Points\n");
    fprintf(fp, "1,qwe,1.1\n");

    int id = 2;
    char *name = "asd";
    float point = 2.2;
    fprintf(fp, "%d,%s,%f\n", id, name, point);

    fclose(fp);
    return 0;
}