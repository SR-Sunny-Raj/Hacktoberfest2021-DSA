// Problem Link: https://cses.fi/problemset/task/1135/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 10000000000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
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
const ll mx = 2*1e5;
const ll logofn = log2(mx);
void dfs(vector<ll> v[], vector<vector<ll>> &par, ll n, ll p, vector<ll> &lvl)
{
	lvl[n] = lvl[p]+1;
	par[n][0] = p;
	For(i,1,logofn)
	par[n][i] = par[par[n][i-1]][i-1];
	FOR(i,v[n].size())
	{
		ll y = v[n][i];
		if(y != p)
		dfs(v,par,y,n,lvl);
	}
}
ll find_lca(vector<ll> v[], vector<vector<ll>> &par, ll a, ll b, vector<ll> &lvl)
{
	if(lvl[a] < lvl[b])
	swap(a,b);
	ll d = lvl[a]-lvl[b];
	while(d > 0)
	{
		ll z = log2(d);
		a = par[a][z];
		d -= (1<<z);
	}
	if(a == b)
	return a;
	rep(i,logofn,0)
	{
		if(par[a][i] != par[b][i])
		{
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
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
		ll n,q;
		cin>>n>>q;
		vector<ll> v[n+1];
		FOR(i,n-1)
		{
			ll a,b;
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);	
		}	
		vector<vector<ll>> par(n+1,vector<ll>(logofn+1,0));
		vector<ll> lvl(n+1,0);
		dfs(v,par,1,0,lvl);
		while(q--)
		{
			ll a,b;
			cin>>a>>b;
			ll z = find_lca(v,par,a,b,lvl);
			cout<<lvl[a]+lvl[b]-2*lvl[z]<<"\n";
		}
		
	}
}