// http://codeforces.com/problemset/problem/1516/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 1e5;
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
ll power(ll a,ll b)
{
    if(b == 0)
    return 1;
    if(b&1)
    return (a%mod * power((a%mod * a%mod)%mod, (b-1)/2)%mod)%mod;
    return power((a%mod * a%mod)%mod, b/2)%mod;
}
ll fact(ll a, ll b)
{
    if(a == b)
    return 1;
    return (a%mod * fact(a-1,b)%mod)%mod;
}
bool sortthis(pair<ll,ll> &a,pair<ll,ll> &b)
{
    return (a.first > b.first);
}
bool prime(ll n)
{
	if(n == 2)
	return true;
	if(n%2 == 0 || n == 1)
	return false;
	for(ll i = 3; (i*i) <= n; i += 2)
	{
		if(n%i == 0)
		return false;
	}
	return true;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	t=1;
	while(t--)
	{
	   ll n;
	   cin>>n;
	   ll arr[n];
	   ll s = 0;
	   FOR(i,n)
	   {
	   		cin>>arr[i];
	   		s += arr[i];
	   }
	   if(s&1)
	   {
	   		cout<<0<<"\n";
	   		continue;
	   }
	   ll dp[n+1][s/2+1];
	   memset(dp,0,sizeof(dp));
	   FOR(i,n+1)
	   dp[i][0] = 1;
	   For(i,1,n)
	   {
	   		For(j,1,s/2)
	   		{
	   			if(j >= arr[i-1])
	   			dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
	   			else
	   			dp[i][j] = dp[i-1][j];
			}
	   }
	   if(dp[n][s/2] == 0)
	   {
	   		cout<<0<<"\n";
	   		continue;
	   }
	   int f = 0;
	   FOR(i,n)
	   {
	   		if(arr[i]&1)
	   		{
	   			cout<<1<<"\n"<<i+1<<"\n";
	   			f = 1;
	   			break;
			}
	   }
	   if(f)
	   continue;
	   ll dp1[s/2+1] = {0};
	   For(i,1,s/2)
	   dp1[i] = INT_MAX;
	   vector<ll> v[s/2+1];
	   For(i,1,s/2)
	   {
	   		if(dp[n][i] == 0)
	   		dp1[i] = 0;
	   		For(j,1,n)
	   		{
	   			if(2*i >= arr[j-1])
	   			{
	   				ll z =  1 + dp1[(2*i-arr[j-1])/2];
	   				if(dp1[i] > z)
	   				{
	   					dp1[i] = z;
	   					v[i] = v[(2*i-arr[j-1])/2];
	   					v[i].pb(j);
					}
				}
			}
	   }
	   cout<<dp1[s/2]<<"\n";
	   FOR(i,v[s/2].size())
	   cout<<v[s/2][i]<<" ";
	   cout<<"\n";
	}
}
