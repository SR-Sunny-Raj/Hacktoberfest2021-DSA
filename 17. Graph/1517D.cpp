// http://codeforces.com/problemset/problem/1517/D
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
ll dfs(vector<ll> v[], ll dis[], bool vis[], ll n)
{
	vis[n] = true;
	stack<ll> s;
	s.push(n);
	while(!s.empty())
	{
		ll p = s.top();
		s.pop();
		for(int i = 0; i < v[p].size(); i++)
		{
			ll y = v[p][i];
			if(vis[y] == false)
			{
				vis[y] = true;
				s.push(y);
				dis[y] = dis[p]+1;
			}
		}
	}
}
ll dfs1(vector<ll> v[], ll node, ll b, vector<ll> &mp, bool vis[])
{
	vis[node] = true;
	if(node == b)
	return 1;
	for(int i = 0; i < v[node].size(); i++)
	{
		ll y = v[node][i];
		if(vis[y] == false)
		{
			mp.pb(y);
			if(dfs1(v,y,b,mp,vis))
			return 1;
			mp.pop_back();
		}
	}
	return 0;
}
ll cl = 0;
ll dfs2(vector<ll> v[], ll n, bool vis[], ll par)
{
	vis[n] = true;
	for(int i = 0; i < v[n].size(); i++)
	{
		ll y = v[n][i];
		if(vis[y] == false)
		{
			dfs2(v,y,vis,n);
		}
	}
	if(par != 0)
	{
		cout<<par<<" "<<n<<" "<<cl<<" "<<n<<"\n";
		cl = n;
	}
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
	   ll n,m,k;
	   cin>>n>>m>>k;
	   ll col[n+1][m], row[n][m+1];
	   memset(col,0,sizeof(col));
	   memset(row,0,sizeof(row));
	   For(i,1,n)
	   {
	   		For(j,1,m-1)
	   		cin>>col[i][j];
	   }
	   For(i,1,n-1)
	   {
	   		For(j,1,m)
	   		cin>>row[i][j];
	   }
	   ll dp[n+1][m+1][k+1];
	   memset(dp,0,sizeof(dp));
	   for(int i = 2; i <= k; i += 2)
	   {
	   		For(j,1,n)
	   		{
	   			For(h,1,m)
	   			dp[j][h][i] = LLONG_MAX;
			}
	   }
	   ll ans[n+1][m+1];
	   memset(ans,0,sizeof(ans));
	   if(k&1)
	   {
	   		For(i,1,n)
		   {
			   	For(j,1,m)
			   	cout<<-1<<" ";
			   	cout<<"\n";
		   }
		   continue;
	   }
	   for(int i = 2; i <= k; i += 2)
	   {
	   		For(j,1,n)
	   		{
	   			For(h,1,m)
	   			{
	   				if(j > 1)
	   				dp[j][h][i] = min(dp[j][h][i], dp[j-1][h][i-2] + 2*row[j-1][h]);
	   				if(h > 1)
	   				dp[j][h][i] = min(dp[j][h][i], dp[j][h-1][i-2] + 2*col[j][h-1]);
	   				if(j < n)
	   				dp[j][h][i] = min(dp[j][h][i], dp[j+1][h][i-2] + 2*row[j][h]);
	   				if(h < m)
	   				dp[j][h][i] = min(dp[j][h][i], dp[j][h+1][i-2] + 2*col[j][h]);
				}
			}
	   }
	   For(i,1,n)
	   {
	   		For(j,1,m)
	   		cout<<dp[i][j][k]<<" ";
	   		cout<<"\n";
	   }	   
	}
}
