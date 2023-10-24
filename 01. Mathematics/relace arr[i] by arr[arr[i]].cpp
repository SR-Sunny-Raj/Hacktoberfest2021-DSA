#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long int n;
	scanf("%ld", &n);
	int arr[n];
	for (long int i = 0; i < n; i++)
	{
		scanf("%ld", &arr[i]);
	}
	for (long int i = 0; i < n; i++)
	{
		long int old = arr[i] % n;
		long int news = arr[old] % n;
		arr[i] = n * news + arr[i];
	}
	for (long int i = 0; i < n; i++)
	{
		cout << arr[i] / n << " ";
	}



	return 0;
}
