#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("tmp.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }

    char row[80];
    char *token;
    while (fgets(row, 80, fp) != NULL) {
        /**
         * The C library function char *fgets(char *str, int n, FILE *stream) reads a line from the specified stream and stores it into the string pointed to by str. It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first.
        */
        printf("Row: %s", row);
        token = strtok(row, ","); 
        while (token != NULL) {
            printf("Token: %s\n", token);
            token = strtok(NULL, ",");
        }

        /***
         * The first call to strtok must pass the C string to tokenize, and subsequent calls must specify NULL as the first argument, which tells the function to continue tokenizing the string you passed in first.

        The return value of the function returns a C string that is the current token retrieved. So first call --> first token, second call (with NULL specified) --> second token, and so on.

        When there are no tokens left to retrieve, strtok returns NULL, meaning that the string has been fully tokenized.
        */
    }

    fclose(fp);
    return 0;
}