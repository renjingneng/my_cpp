#include <stdio.h>
#include <stdlib.h>

 
int maxSubArrayProduct(int a[], int size)
{
    int* dp_max = (int*) malloc(size * sizeof(int));
    int* dp_min = (int*) malloc(size * sizeof(int));
    int ans;
    int curr;

    dp_max[0] = a[0];
    dp_min[0] = a[0];
    ans = a[0];
    for (int i = 1; i < size; i++) {
        dp_max[i] = max(a[i],max(dp_max[i-1] * a[i], dp_min[i-1] * a[i]));
        dp_min[i] = min(a[i],min(dp_max[i-1] * a[i], dp_min[i-1] * a[i]));
        ans = max(dp_max[i],ans);
    }
    return ans;
}
 

int main()
{
    int a[] = { -2,6,4 };
    int n = sizeof(a) / sizeof(a[0]);
    int ans;
    ans = maxSubArrayProduct(a, n);
    printf("%d",ans);
    return 0;
}