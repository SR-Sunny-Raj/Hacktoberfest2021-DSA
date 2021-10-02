#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N=1000;
int n,m;
int a[N+1][N+1];
bool flag[N+1][N+1];
vector<pair<int,int> > ans;
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
}
int recursion(int x,int y,int val)
{
   if(!flag[x][y] || a[x][y]!=val || x>n || y>m)return 0;
   flag[x][y]=false;
   int count=1;
   count=1+recursion(x-1,y,val)+recursion(x,y-1,val)+recursion(x+1,y,val)+recursion(x,y+1,val);
   return count;
}
void solve()
{
   cin>>n>>m;
   memset(flag,true,sizeof(flag));
   memset(a,0,sizeof(a));
   for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)
     {
        if(flag[i][j])
        {
           ans.push_back(make_pair(recursion(i,j,a[i][j]),a[i][j]));
        }
     }
   }
   sort(ans.begin(),ans.end(),comp);
   cout<<ans[0].second<<" "<<ans[0].first<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
    solve();
  return 0;
}
