#include "stdio.h"

int main(){
    int a=10,x,y,z;
    x=a--;//x=10,a=9
    y=--a;//y=8,a=8
    z=10*x--;//z=100,x=9
    printf("%d,%d,%d\n",z,y,x);//100,8,9
    return 0;
}