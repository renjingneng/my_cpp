// reference：https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include <vector>
#include <iostream>
using namespace std;

vector<int> lengthOfLIS(vector<int>& nums)
{
	int n = nums.size();
	vector<int> ans;
	ans.push_back(nums[0]);
	printf("[LOG]:ans.push_back(%d) \n",nums[0]);

	for (int i = 1; i < n; i++) {
		if (nums[i] > ans.back()) {
			ans.push_back(nums[i]);
			printf("[LOG]:ans.push_back(%d) \n",nums[i]);
		}
		else {
			int low = lower_bound(ans.begin(), ans.end(),
								nums[i])
					- ans.begin();
			ans[low] = nums[i];
			printf("[LOG]:ans[%d] = %d \n",low,nums[i]);
		}
	}
	return ans;
}


int main()
{
	vector<int> nums;
	//10, 7, 12, 33, 21, 50, 41, 48
	nums.push_back(10);
	nums.push_back(7);
	nums.push_back(12);
	nums.push_back(33);
	nums.push_back(21);
	nums.push_back(50);
	nums.push_back(41);
	nums.push_back(48);

    vector<int> ans = lengthOfLIS(nums);
	printf("Length of LIS is %d\n", ans.size());
	printf("Content of LIS is ");
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
	return 0;
}
