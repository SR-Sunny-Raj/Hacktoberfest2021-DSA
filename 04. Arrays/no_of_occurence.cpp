#include<bits/stdc++.h>
using namespace std;

int check(int arr[], int n, int a)
{
	int ans = 0;
	for (int i=0; i<n; i++)
{


		if (a == arr[i])
        {


		ans++;
        }
}
	return ans;

}

int main()
{
	int arr[] = {1, 2, 3, 4, 4, 5, 5, 4 ,6 ,8 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int a = 4;
	cout << check(arr, n, a);
	return 0;
}

