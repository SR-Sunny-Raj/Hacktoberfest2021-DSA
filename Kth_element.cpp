// Program to find kth element from two sorted arrays
#include <iostream>
using namespace std;

int kth(int arr1[], int arr2[], int m, int n, int k)
{
	int sorted1[m + n];
	int i = 0, j = 0, d = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			sorted1[d++] = arr1[i++];
		else
			sorted1[d++] = arr2[j++];
	}
	while (i < m)
		sorted1[d++] = arr1[i++];
	while (j < n)
		sorted1[d++] = arr2[j++];
	return sorted1[k - 1];
}

// Driver Code
int main()
{
	int arr1[5] = {7,9,0,5,6};
	int arr2[4] = {1,8,99,56};
	int k = 5;
	cout << kth(arr1, arr2, 5, 4, k);
	return 0;
}
