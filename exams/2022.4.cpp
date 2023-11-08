#include "stdio.h"
#include "stdlib.h"

int fun(int &x,int *y){
    int temp =*y;
    *y=x;
    x=temp;
    return x/(*y);
}

int main()
{
    int x=222,*y=(int*)malloc(sizeof(int));
    *y=555;
    int m = 11;
    //printf("%d\n",(*y)*fun(x,y)); 444
    //printf("%d\n",x*fun(x,y)); 1110
    printf("%d\n",m*++m); //144
    free(y);
    return 0;
}