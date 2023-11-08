#include "stdio.h"



int main()
{
    int arr[] = {1,2,3,40,50,6,7,8};
    int *p = arr+sizeof(arr)/sizeof(int)-1;
    printf("%d\n",*p);//8
    *p--+=123;//*(p--)+=123;
    printf("%d\n",*p--);//7
    printf("%d\n",(*p)--);//6
    printf("%d\n",*--p);//50
    printf("%d\n",--*p);//49
    return 0;
}