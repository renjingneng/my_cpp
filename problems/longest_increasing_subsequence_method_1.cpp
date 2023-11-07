// reference：https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
#include <vector>
#include <iostream>
using namespace std;



vector<int> lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}

int main()
{
	vector<int> nums;
	vector<int> subseq;
	//100, 104, 106, 101, 3, 4, 2, 9, 10, 5
	nums.push_back(100);
	nums.push_back(104);
	nums.push_back(106);
	nums.push_back(101);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(9);
	nums.push_back(10);
	nums.push_back(5);
	subseq = lis(nums);

	printf("Length of LIS is %d\n", subseq.size());
	printf("Content of LIS is ");
	for(int i = 0; i < subseq.size(); i++) {
        cout << subseq[i] << " ";
    }
    cout << endl;
	return 0;
}
