#include<bits/stdc++.h>
using namespace std;


typedef  long long  ll;

 vector <set<int>> a;
 vector <pair<int,int>> c;
 vector <int> d;
 set<int> b;
 void dfs(int v,map<int,vector<int>> &mapa,vector <bool> &visited,int pa)
 { 
   visited[v]=true;
    d.push_back(v);
    for(int i=0;i<mapa[v].size();i++)
    {
      if(!visited[mapa[v][i]])
      {
        dfs(mapa[v][i],mapa,visited,v);
        d.push_back(v);
      }
    }





 } 

  

int main()
{ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  



 int t=1;
 //cin>>t;
 while(t>0)
 { 
   int n;
   cin>>n;
   map<int,vector <int>> mapa;
   for(int i=0;i<n-1;i++)
   {
    int u,v;
    cin>>u>>v;
    mapa[u].push_back(v);
     mapa[v].push_back(u);
   } 
   vector <bool> visited(n+1,false);
    
    dfs(1,mapa,visited,1);
    cout<<"? "<<n<<" ";
    for(int i=0;i<n;i++)
    {
      cout<<i+1<<" ";
    }
    cout<<endl;
    int mx;
    cin>>mx;
    b.insert(1);
    for(int i=1;i<d.size();i++)
    {
      b.insert(d[i]);
      a.push_back(b);
      c.push_back({d[i],d[i-1]});
    }
    int lo=0;
    int hi=a.size()-1;
    int ans;
    while(lo<=hi)
    {
      int mid=(lo+hi)/2;
      cout<<"? ";
      cout<<a[mid].size()<<" ";
      auto it=a[mid].begin();
      while(it!=a[mid].end())
      {


      cout<<*it<<" ";

        it++;
      }
      cout<<endl;
      int now;
      cin>>now;
      if(now==mx)
      {
        hi=mid-1;
        ans=mid;
      }
      else
      {
        lo=mid+1;

      }
    }

     cout<<"! "<<c[ans].first<<" "<<c[ans].second<<endl;
  

  t--;
 }  
   




}