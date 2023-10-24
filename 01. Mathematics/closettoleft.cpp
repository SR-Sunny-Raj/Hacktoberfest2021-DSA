#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main()
{
	IOS;
	int n, t;
	cin >> n >> t;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	while (t--)
	{
		int va;
		cin >> va;
		int l = -1;
		int r = n;
		while (r > l + 1)
		{
			int mid = l + (r - l) / 2;
			if (va >= arr[mid])
				l = mid;
			else
				r = mid;
		}
		cout << l + 1 << endl;
	}



	return 0;
}
