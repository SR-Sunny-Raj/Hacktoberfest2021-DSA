#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

int n;
unordered_map<int,bool> visited;

void dfs(int u, int p, vector<vector<int>>& memo, int lvl[], int log, vector<vector<int>> &g)
{
    // Using recursion formula to calculate
    // the values of memo[][]
    memo[u][0] = p;
    for (int i = 1; i <= log; i++)
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v != p)
        {
            lvl[v] = lvl[u] + 1;
            dfs(v, u, memo, lvl, log, g);
        }
    }
}

int lca(int u, int v, int log, int lev[], vector<vector<int>>& memo)
{
    // The node which is present farthest
    // from the root node is taken as u
    // If v is farther from root node
    // then swap the two
    if (lev[u] < lev[v])
        swap(u, v);
 
    // Finding the ancestor of u
    // which is at same level as v
    for (int i = log; i >= 0; i--)
        if ((lev[u] - pow(2, i)) >= lev[v])
            u = memo[u][i];
 
    // If v is the ancestor of u
    // then v is the LCA of u and v
    if (u == v)
        return u;
 
    // Finding the node closest to the root which is
    // not the common ancestor of u and v i.e. a node
    // x such that x is not the common ancestor of u
    // and v but memo[x][0] is
    for (int i = log; i >= 0; i--)
    {
        if (memo[u][i] != memo[v][i])
        {
            u = memo[u][i];
            v = memo[v][i];
        }
    }
 
    // Returning the first ancestor
    // of above found node
    return memo[u][0];
}

void dfsXor(int v,int val,unordered_map<int,int>&xorr,int arr[],vector<vector<int>> &g){
    visited[v]=true;
    xorr[v]=arr[v]^val;

    for(auto i=g[v].begin();i!=g[v].end();i++){
        if(!visited[(*i)]){
            dfsXor(*i,arr[v]^val,xorr,arr,g);
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t>0)
    {
        int q;
        cin>>n>>q;
        vector<vector<int>>g(n+10);
        int arr[n+10],lvl[n+10];


        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<=n+4;i++){
            lvl[i]=0;
            visited[i]=false;
        }

        int u,v;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int logg=(int)ceil(log2(n));

        vector<vector<int>> memo(n+10,vector<int>(logg+1,-1));

        dfs(1, 1, memo, lvl, logg, g);

        unordered_map<int,int>xorr;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfsXor(i,0,xorr,arr,g);
            }
        }

        for(int i=0;i<q;i++){
            cin>>u>>v;
            
            int anc=lca(u,v, logg, lvl, memo);
            
            int t1=xorr[u]^xorr[v];
            int t2=t1^arr[anc];
            //cout<<"anc "<<anc<<" "<<" xorr[u] "<<xorr[u]<<" xorr[v] "<<xorr[v]<<" "; 
            cout<<t2<<endl;
        }

        t--;
    }
    

    return 0;
}
