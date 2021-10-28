#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define all(x) (x).begin(),(x).end()
#define vll vector<ll>
#define vi vector<ll>
#define vp vector<pi>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define POB pop_back 
#define f(i,x,z) for(ll i=x;i<z;i++)
#define debug(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define clr(x) memset(x, 0, sizeof(x)) 
#define setall(x,a) memset(x, a, sizeof(x))
#define INF 1000000000000000003 
#define mathpi 3.141592653589793238 
#define F first;
#define S second;
#define vpair vector<pair<ll,ll>>
#define vpairs vector<pair<string,string>>
#define tin tuple<ll,ll,ll>
#define rev(i,x,z) for(ll i=x;i>=z;i--)    
vector<vi>adj;
int head;
queue<ll>q;
ll ptr=0;
vector<bool> visited(1000001,0);
vector<ll> color(1000001,-1);
bool bfs(ll val)
{
	visited[val]=1;
	color[val]=0;
	q.push(val);
	while(q.size()!=0)
	{
		ll cur=q.front();
		q.pop();
		ll cur_color=color[cur];
		for(auto x:adj[cur])
		{
			if(color[x]==cur_color)
			{
				cout<<"Non Biparite"<<"\n";
				return 0;
			}
			else{
				color[x]=abs(cur_color-1);
			}
			if(visited[x]!=1)
			{
				visited[x]=1;
				q.push(x);
			}
		}
	}
	return 1;
}
int main()
{
	// freopen("inp.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);// Input and output clearance
	cin.tie(0);
	ll n;
	cin>>n;
	adj.resize(1000000);
	f(i,0,n)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	head=1;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            if(bfs(i)==0)
			{
				break;
			}
			else{
				cout<<"Biparite"<<"\n";
				f(i,1,n+1)
				{
					cout<<color[i]<<" ";
				}
			}
        }
    }
	
}
