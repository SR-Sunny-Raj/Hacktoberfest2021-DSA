#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x <<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector < vector <T> > v){cerr<<"["<<endl; {for(vector<T> vec1:v){for(T x:vec1){cerr<<x<<" ";}cerr<<endl;}}cerr<<"]";}
vector<ll> adj[100000];
vector<ll> nodes;
vector<ll> vis;
void addEdge(ll a, ll b)
{
    a--;
    b--;
    debug(a)
    debug(b)
    adj[a].pb(b);
    adj[b].pb(a);
}
void dfs(ll i){
    vis[i]=1;
    ll j=0,u;
    if(adj[i].size()>0)
    for (ll j=0;j<adj[i].size();j++) {
        u=adj[i][j];
        if (vis[u]==0)
            dfs(u);
    }
    debug(vis)
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w",stderr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fastio
    ll n,k,i,j,l,m;
    cin>>n>>k;
    vis.resize(n,0);
    while(k--)
    {
        cin>>i>>j;
        addEdge(i,j);
    }
    debug(vis)
    m=adj[0].size();
    debug(m)
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            nodes.pb(i);
        }
    }
    l=nodes.size();
    cout<<l<<"\n";
    return 0;
}
