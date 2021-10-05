
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll x,vector<ll>& pos, ll k)
{
	ll pairs = 0;

int	p = 0;
	for (int i = pos.size() - 1; i >= 0; i--) {
		while (p <pos.size() and pos[i] + pos[p] <= x)
			{
				p++;
			}
						//	cout<<"the pair is"<<p<<i<<x<<"\n";

		pairs += min(p, i+1);
	}


	return (pairs >= k);
}

ll kth_element(ll a[],int n,ll k)
{
	vector<ll> pos;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0)
			pos.push_back(a[i]);

	}

	sort(pos.begin(), pos.end());

	ll l = 0,ans = 0, r = 1e18;

	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid, pos, k)) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}

	return ans;
}



int main() {
	int n;
	ll k;
	cin >> n>>k;
	ll a[n];									
	for(int i=0;i<n;i++)
	cin>>a[i];


	cout << kth_element(a, n, k)<<"\n";

}
