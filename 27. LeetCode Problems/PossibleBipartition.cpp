//Problem Link:

//https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    
    bool isBipartiteBfs(vector<vector<int>>& adj,int N,int node,vector<int>& color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        //Process current graph component using BFS
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int ele: adj[curr])
            {
                if(color[ele]==color[curr]) //Odd-cycle
                    return false;
                if(color[ele]==-1)  //Unvisited node
                {
                    color[ele] = 1-color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }
  
  bool isBipartiteDfs(vector<vector<int>>& adj,int N,int node,vector<int>& color)
    {
        
        //Process current graph component using DFS
        
            for(auto itr: adj[node])
            {
                
                if(color[itr]==-1)  //Unvisited node
                {
                    color[itr] = 1-color[node];
                    if(!isBipartiteDfs(adj,N,itr,color))
                        return false;
                }
                else if(color[itr]==color[node]) //Odd-cycle
                    return false;
            }
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
     ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> adj(N+1);
        for(int i=0;i<dislikes.size();++i)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> color(N+1,-1);
        for(int i=1;i<=N;++i)
            if(color[i]==-1)
                if(!isBipartiteBfs(adj,N,i,color)) //isBipartiteBfs or isBipartiteDfs change according to the approach being used to solve problem
                    return false;
        return true;   
    }
};
