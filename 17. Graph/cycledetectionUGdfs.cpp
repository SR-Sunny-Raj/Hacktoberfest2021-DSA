//cycle detection in undirected graph using dfs
#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int>adj[] , int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


bool cycle(vector<int>adj[] , int s , int par , vector<bool>&visited){
    visited[s]=1;
    for(auto x : adj[s]){
        if(visited[x]==false){
            if(cycle(adj , x , s , visited)==true){
                return true;
            }
            else if ( x != par){
                return true;
            }
        }
    }
    return false;
}

bool dfs_cycle( vector<int>adj[] , int V){
    vector<bool>visited(V , 0);
    for(int i  = 0 ; i< V ; i++){
        if(visited[i]==false){
            if(cycle(adj , i , -1 , visited)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V = 4;
    vector<int>adj[V];
    addEdge(adj , 0 , 1);
    addEdge(adj , 0 , 2);
    addEdge(adj , 1 , 2);
    addEdge(adj , 1 , 3);
    cout<<dfs_cycle(adj , V);
    return 0;
    
}