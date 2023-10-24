//cycle detection in undirected graph using dfs
//backedge concept

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[] , int u , int v){
    adj[u].push_back(v);
}
bool cycle(vector<int>adj[] , int s , vector<bool>&visited , vector<bool>&recSt){
    visited[s]=1;
    recSt[s]=1;
    for(auto x : adj[s]){
        if(visited[x]==false ){
            if(cycle(adj , x , visited , recSt )==true){
                return true;
            }

        }
        else if(recSt[x]==true){
            return true;
        }
    }
    recSt[s]=false;
    return false;
}


bool dfs(vector<int>adj[] , int V){
    vector<bool>visited(V , 0);
    vector<bool>recSt(V , 0);
    for(int i =0 ; i<V ; i++){
        if(visited[i]==false){
            if(cycle(adj , i , visited , recSt)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V=6;
    vector<int>adj[V];
    addEdge(adj , 0 , 1);
    addEdge(adj , 2 , 1);
    addEdge(adj , 2 , 3);
    addEdge(adj , 3 , 4);
    addEdge(adj , 4 , 5);
    addEdge(adj , 5 , 3);
    cout<<dfs(adj , V);
    return 0;
}
