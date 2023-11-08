#include "stdio.h"
#include "stdlib.h"



int main()
{
    char a[6] = {'a','b','c','d','w','d'};
    char* temp= (char*)(&a);
    /******
     * This line is a bit tricky. `&a` gives the address of the array `a`, not the first element. When you add 1 to it (`&a+1`), it points to the memory location after the entire array `a` because `a` is an array of chars. The cast to `(char*)` makes `ptr` a pointer to the character at that location.
    */
    char * ptr=(char*)(&a+1);
    printf("%c,%c,%c\n", *(a+1),*(ptr-1),*temp);
    return 0;
}