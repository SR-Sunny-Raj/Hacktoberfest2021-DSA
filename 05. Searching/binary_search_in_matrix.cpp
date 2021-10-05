/* Author : VANSH KAPILA */

/* "The greatest glory in living lies not in never falling, but in rising every time we fall." -*/

#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define int long long
#define ld long double
#define endl "\n";

const int mod = 1000000007;
using namespace std;


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test = 1;
	//cin >> test;
	while (test--) {

		int n, m;
		cin >> n >> m;
		int arr[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		int key;
		cin >> key;
		bool found  = false;
		for (int i = 0; i < n; i++)
		{
			int a[m];
			for (int j = 0; j < m; j++)
			{
				a[j] = arr[i][j];
			}

			if (binary_search(a, a + m, key) == true)
			{
				cout << 1 << endl;
				found = true;
				break;
			}

		}
		if (found == false)
		{
			cout << 0 << endl;
		}

	}
	return 0;
}