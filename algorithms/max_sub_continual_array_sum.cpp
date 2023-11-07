#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
    int ans;
    int ans_index;
    int* dp = (int*) malloc(n * sizeof(int));
    int* track = (int*) malloc(n * sizeof(int));
    vector<int> print_list;


    dp[0] = a[0];
    ans = a[0];
    track[0]=-1;
    ans_index = 0;
    for (int i = 1; i < n; i++) {
        if(a[i]>(a[i] + dp[i - 1])){
            track[i]=-1;
            dp[i] = a[i];
        }else{
            track[i]=i - 1; 
            dp[i] = a[i] + dp[i - 1]; 
        }
        if(dp[i]>ans){
            ans = dp[i];
            ans_index = i;
        }
    }
    
    printf("Max sum is %d\n",ans);
	printf("Content  is ");
    while (ans_index != -1) {
        print_list.push_back(a[ans_index]);
        ans_index = track[ans_index];
    }
    reverse(print_list.begin(), print_list.end());
    for(int i = 0; i < print_list.size(); i++) {
        cout << print_list[i] << " ";
    }
    
    return 0;
}