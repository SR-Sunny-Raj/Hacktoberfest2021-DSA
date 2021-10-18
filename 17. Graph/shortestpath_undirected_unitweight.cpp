//shortest path in unitweight and undirected graph
// time:O(n+e) 
#include<bits/stdc++.h>
using namespace std;
void shortestpath(vector<int> &distance,vector<int>adj[],int start)
{
     queue<int>q;
     q.push(start);
     distance[start]=0;
     while(!q.empty())
     {
         int curr=q.front();
         q.pop();
         for(auto it:adj[curr])
         {
             if(distance[curr]+1<distance[it])
             {
                 q.push(it);
                 distance[it]=distance[curr]+1;
             }
         }
     }
}
int main()
{
int v,e;
cin>>v>>e;
vector<int>adj[v+1];

for(int i=0;i<e;i++)
{
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
}
int start;
cin>>start;
vector<int>distance(v+1,INT_MAX);
 shortestpath(distance,adj,start);

for(int i=1;i<=v;i++)
{
    cout<<i<<" "<<distance[i]<<endl;
}
return 0;
}