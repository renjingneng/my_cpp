#include "stdio.h"

int main()
{
    FILE * fp = NULL;
    char s[] = "How to tell a story?",ch;
    fp=fopen("data.txt","w");
    fprintf(fp,"%s",s);
    fclose(fp);
    fp=fopen("data.txt","r");
    //This line moves the file pointer fp to the 5th character in the file (since the offset is 0-based).
    fseek(fp,4,SEEK_SET);
    //after fgetc fp move forward one char
    while ((ch=fgetc(fp))!=EOF)
    {
        if(ch=='t'){
            //ftell(fp) = offset
            s[ftell(fp)-2]='\0';
        }
    }
    printf("%s\n",s);
    fclose(fp);
    return 0;
}