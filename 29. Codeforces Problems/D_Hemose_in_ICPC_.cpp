//Somos insignificantes. Por mais que você programe sua vida, a qualquer momento tudo pode mudar.
// If you have God on your side,everything becomes clear

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//To convert it into pairs use pair<int,int> instead of int and also make less_equal<pair<int,int>> 

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// To use ordered use ordered_multiset<type>S something like this

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define fi first
#define popcount(x) __builtin_popcountll(x)
#define se second
#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
/*void Sieve(int n) 
{ 
    
    //bool prime[n+1]; 
    //memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    
} */
/* struct cmp{
    bool operator()(const pair<int,int>& v1,const pair<int,int>& v2) const{
    	
    }};*/
 long long binpow(long long a, long long b) {
    a %=MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    res=res%MOD;
    return res;
}
   


  
const int mxN = 1005;
vector<ll> adj[mxN];
ll par[mxN];
ll tin[mxN],tout[mxN];
vector<ll> order;
ll t=0;
 

void dfs(int src,int p){
    par[src]=p;
    order.push_back(src);
    tin[src]=t;
    t++;
    for(auto & child:adj[src]){
        if(child==p)continue;
        dfs(child,src);
    }
    tout[src]=t-1;
}
 
int query(int n) {
    cout << "? " << n;
    for(int i=0;i<n;i++) {
        cout<<" "<<order[i];
    }
    cout<<endl;
    int ans;
    cin>>ans;
    return ans;
}
 
void solve() {
    int n;
    cin>>n;
    for(int i =1; i<n;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1,-1);
    int l = 1, r = n-1;
    int x = query(n);
    
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(query(mid)==x) {
            r = mid-1;
            ans = mid;
        } else {
            l = mid+1;
        }
    }
 
    cout << "! " << order[ans] << " " << par[order[ans]]<< endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int tc=1;// cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}