//cycle detection in undirected graph using bfs
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[] , int u , int v){
     adj[u].push_back(v);
     adj[v].push_back(u);
}

bool cycle(vector<int>adj[] , int s , int par , vector<bool>&visited){
    queue<pair<int , int>>q;
    q.push({s , par});
    visited[s]=1;
    while(!q.empty()){
        int vertex = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto x : adj[vertex]){
            if(visited[x]==false){
                q.push({x , vertex});
                visited[x]=1;
            }
            else if( x != parent){
                return true;
            }

        }



    }
    return false;

} 

bool cycledetection(vector<int>adj[] , int V){

    vector<bool>visited(V , 0);
    int i =0 ;
    for(int i =0 ; i<V ; i++ ){
        if(visited[i]==0){
            if(cycle(adj , i , -1 ,  visited)==true){
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
    cout<<cycledetection(adj , V);
    return 0;

}