// time:O(n+e) 
//kosaraju algorithm for strongly connected component

#include<bits/stdc++.h>
using namespace std;
void dfstrverse(vector<int> &visited,vector<int>adj[],stack<int> &st,int node)
{
         visited[node]=1;
         for(auto it:adj[node])
         {
             if(!visited[it])
             {
                  dfstrverse(visited,adj,st,it);
             }
         }
         st.push(node);
}
void revdfs(vector<int> &visited,vector<int>rev[],stack<int> &st,int node)
{
         visited[node]=1;
         cout<<node<<" ";
         for(auto it:rev[node])
         {
             if(!visited[it])
             {
                  revdfs(visited,rev,st,it);
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
   
}

vector<int>visited(v+1,0);
stack<int>st;
for(int i=1;i<=v;i++)
{
    if(!visited[i])
    {
        dfstrverse(visited,adj,st,i);
    }
}
vector<int>rev[v+1];
for(int i=1;i<=v;i++)
{
    visited[i]=0;
    for(auto it:adj[i])
    {
        rev[it].push_back(i);
    }
}
while(!st.empty())
{
    int node=st.top();
    st.pop();
    if(!visited[node])
    {
        revdfs(visited,rev,st,node);
        cout<<endl;
    }
}
return 0;
}