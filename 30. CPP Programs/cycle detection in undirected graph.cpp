#include <bits/stdc++.h>
#define IOS                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define endl "\n"
#define ll long long int 
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define pq priority_queue<int,vi,greater<int> >
using namespace std;
vi arr[10001];
int vis[10001];
int in_time[11];
vi res;
bool kahn(int n)
{
   queue<int> q;
   for(int i=1;i<=n;i++)
   {  if(in_time[i]==0)
       q.push(i);
   }
   while(!q.empty())
   {
       int curr=q.front();
       res.pb(curr);
       q.pop();
       for(int child : arr[curr])
       {
           in_time[child]--;
           if(in_time[child]==0)
           q.push(child);
       }
   }
   cout<<"Top sort: ";
   for(int node : res)
   cout<<node<<" ";
   
}
int main()
{
   IOS;
   int vertices,edges;
   cin>>vertices>>edges;
   int u,v;
  for(int i=1;i<=edges;i++)
   {
       cin>>u>>v;
       arr[u].pb(v);
       in_time[v]++;
   }
   kahn(vertices);
} 
