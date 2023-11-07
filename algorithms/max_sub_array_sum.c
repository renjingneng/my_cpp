#include <stdio.h>
#include <stdlib.h>

 
int maxSubArraySum(int a[], int size)
{
    int* dp = (int*) malloc(size * sizeof(int));
    dp[0] = a[0];
    int ans = dp[0];
    for (int i = 1; i < size; i++) {
        dp[i] = max(a[i], a[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    return ans;
}
 

int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
    int ans;
    ans = maxSubArraySum(a, n);
    printf("%d",ans);
    return 0;
}