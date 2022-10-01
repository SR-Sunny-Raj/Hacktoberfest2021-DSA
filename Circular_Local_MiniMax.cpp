//  https://codeforces.com/contest/1686/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(ll i = x; i >= y; i--)
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define errAA(A) for(auto i:A){errA(i)};
#define err1(a) cout<<#a<<" "<<a<<"\n"
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<"\n"
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<"\n"
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 1e6;
/*ll numinv[mx+1];
void InverseofNumber(ll p)
{
    numinv[0] = numinv[1] = 1;
    for (ll i = 2; i <= mx; i++)
        numinv[i] = numinv[mod % i] * (mod - mod / i) % mod;
}
ll fac[mx+1] = {0}, infac[mx+1] = {0};
ll comb(ll n, ll r)
{
	if(r > n)
	return 0;
	return (fac[n]%mod * infac[r]%mod * infac[n-r]%mod)%mod;
}*/
ll power(ll a, ll b, ll m)
{
	if (b == 0)
		return 1;
	if (b & 1)
		return (a % m * power((a % m * a % m) % m, (b - 1) / 2, m) % m) % m;
	return power((a % m * a % m) % m, b / 2, m) % m;
}
ll fact(ll a, ll b)
{
	if (a == b)
		return 1;
	return (a % mod * fact(a - 1, b) % mod) % mod;
}
bool sortthis(pll &a, pll &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return (a.first > b.first);
}
bool prime(ll n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0 || n == 1)
		return false;
	for (ll i = 3; (i * i) <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll T = 1;
	cin >> T;
	while (T--)
	{
		ll n;
		cin >> n;
		vll arr(n);
		FOR(i, n)
		cin >> arr[i];
		ll f = 0;
		sort(all(arr));
		ll i = 0, j = (n + 1) / 2;
		vll ans;
		while (j < n)
		{
			ans.pb(arr[i]);
			ans.pb(arr[j]);
			++i, ++j;
		}
		while (i < (n + 1) / 2)
			ans.pb(arr[i]), ++i;
		ll m = ans.size();
		FOR(i, m)
		{
			ll a = ans[(i - 1 + m) % m], b = ans[(i + 1) % m];
			if ((a > ans[i] && ans[i] < b) || (a < ans[i] && ans[i] > b))
				continue;
			f = 1;
		}
		if (f)
			noo;
		else
		{
			yess;
			errA(ans);
		}
	}
#ifndef ONLINE_JUDGE
	printf("\nRun Time -> %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
}
