class Solution {
public:
    vector<int>vis;
    vector<vector<int>>graph;
    void dfs(int u , int par){
        vis[u]=1;
        for(auto v : graph[u]){
            if(v==par)continue;
            if(vis[v] != 1)dfs(v,u);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1)return -1;
        vis.resize(n);
        graph.resize(n);
        for(int  i = 0 ; i< m;i++){
            int u = connections[i][0], v = connections[i][1] ;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int dissconnected =0;
        for(int  i = 0 ; i< n ;i++){
            if(vis[i] !=1){
                dfs(i,-1);
                dissconnected++ ;
            }
        }
        dissconnected-- ;
        
        return dissconnected;
    }
};