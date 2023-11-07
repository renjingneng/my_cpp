#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int a[] = {-2, 6, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int ans;
    int ans_index;
    int *track = (int *)malloc(n * sizeof(int));
    int *dp_max = (int *)malloc(n * sizeof(int));
    int *dp_min = (int *)malloc(n * sizeof(int));
    int temp;
    vector<int> print_list;

    dp_max[0] = a[0];
    dp_min[0] = a[0];
    ans = a[0];
    track[0] = -1;
    ans_index = 0;
    for (int i = 1; i < n; i++)
    {
        temp = max(dp_max[i - 1] * a[i], dp_min[i - 1] * a[i]);
        if (a[i] > temp)
        {
            track[i] = -1;
            dp_max[i] = a[i];
        }
        else
        {
            track[i] = i - 1;
            dp_max[i] = temp;
        }
        if (dp_max[i] > ans)
        {
            ans = dp_max[i];
            ans_index = i;
        }
        dp_min[i] = min(a[i], min(dp_max[i - 1] * a[i], dp_min[i - 1] * a[i]));
    }
    printf("Max product is %d\n", ans);
    printf("Content  is ");

    while (ans_index != -1)
    {
        print_list.push_back(a[ans_index]);
        ans_index = track[ans_index];
    }
    reverse(print_list.begin(), print_list.end());
    for (int i = 0; i < print_list.size(); i++)
    {
        cout << print_list[i] << " ";
    }

    return 0;
}