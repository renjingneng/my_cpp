#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE *fp = NULL;
    long len;
    fp = fopen("data.dat", "wb");
    for (int i = 0; i < 9; i++)
        fprintf(fp, "%d", i + 1);
    fclose(fp);
    fp = fopen("data.dat", "r");
    while (fgetc(fp) != EOF);
    len = ftell(fp);//123456789X
    fseek(fp, -len / 2, SEEK_END); // SEEK END 指示文件结束位置
    printf("%c\n", fgetc(fp));//6
    fclose(fp);
    return 0;
}

// int main()
// {
//     FILE *fp = NULL;
//     long len;
//     fp = fopen("data.dat", "w");
//     for (int i = 0; i < 2; i++)
//         fprintf(fp, "%c", 'b');
//     fclose(fp);
   

//     fp = fopen("data.dat", "r");
//     char temp=fgetc(fp);
//     while (temp!= EOF)
//     {
//        printf("%c", temp);
//        temp=fgetc(fp);
//     }
    
//     return 0;
// }