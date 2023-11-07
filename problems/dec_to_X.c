#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec_to_bin(int n)
{
    if(n==0){
        return ;
    }else{
        dec_to_bin(n/2);//n/2 变成整数具有floor()函数作用1.5->1
        printf("%d",n%2);
    }
}

void dec_to_oct(int n)
{
    if(n==0){
        return ;
    }else{
        dec_to_oct(n/8);//n/2 变成整数具有floor()函数作用1.5->1
        printf("%d",n%8);
    }
}

void dec_to_hex(int n)
{
    if(n==0){
        return ;
    }else{
        dec_to_hex(n/16);
        int digit = n%16;
        if(digit>9){
            printf("%c",('A'+(digit-10)));
        }else{
            printf("%d",digit);
        }        
    }
}

int main()
{
    //5[dec] = 1*2^2 + 0*2^1 + 1*2^0
    puts("dec_to_bin:");
    dec_to_bin(333);
    puts("\n-----");
    puts("dec_to_oct");
    dec_to_oct(333);
    puts("\n-----");
    puts("dec_to_hex");
    dec_to_hex(333);
    return 0;
}