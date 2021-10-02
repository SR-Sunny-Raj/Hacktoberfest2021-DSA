#include<bits/stdc++.h>
using namespace std;
void pigeonholeSort(int arr[], int n)
{
	int mini = arr[0], maxi = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < mini)
			mini = arr[i];
		if (arr[i] > maxi)
			maxi = arr[i];
	}
	int range = maxi - mini + 1; 
	vector<int> holes[range];
	for (int i = 0; i < n; i++)
		holes[arr[i]-mini].push_back(arr[i]);
	int index1 = 0;
	for (int i = 0; i < range; i++)
	{
	vector<int>::iterator it;
	for (it = holes[i].begin(); it != holes[i].end(); ++it)
			arr[index1++] = *it;
	}
}
int main()
{
	int arr[] = {8, 30, 12, 7, 14, 6, 18};
	int n = sizeof(arr)/sizeof(arr[0]);

	pigeonholeSort(arr, n);

	printf("Sorted order is : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
