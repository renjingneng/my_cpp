#include <stdio.h>

void findSubsets(int nums[], int n)
{
	printf("no 1 set\n");
	printf("empty set\n");

	for (int i = 1; i < (1 << n); i++) {
		printf("no %d set\n",i+1);
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) != 0) {
				printf("%d",nums[j]);
			}
		}
		printf("\n");
	}
}


int main()
{
	int arr[] = { 1, 2, 3 };
	int n = sizeof(arr)/sizeof(arr[0]);
	findSubsets(arr, n);
}
