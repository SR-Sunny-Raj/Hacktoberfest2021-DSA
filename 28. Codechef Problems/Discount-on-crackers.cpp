#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define M 1000000007
using namespace std;
vector<ll> v[26];
bool flag[26][26];
void mark(int x,int y)
{
  flag[x][y]=true;
  for(auto b : v[y])
    if(!flag[x][b])
      mark(x,b);
}
void solve()
{
   for(int i=0;i<26;i++)v[i].clear();
   memset(flag,false,sizeof(flag));
   string s,t;
   cin>>s>>t;
   int n;
   cin>>n;
   while(n--)
   {
     string c;
     cin>>c;
     v[c[0]-'a'].push_back(c[3]-'a');
   }
   if(s.length()!=t.length())
   {
     cout<<"NO"<<endl;
     return;
   }
   for(int i=0;i<26;i++)
   {
     flag[i][i]=true;
     for(auto a : v[i])
       if(!flag[i][a]) 
          mark(i,a); 
   }
   bool ans=true;
   for(int i=0;i<s.length() && ans;i++)if(!flag[s[i]-'a'][t[i]-'a'])ans=false;
   cout<<(ans ? "YES" : "NO")<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  cin>>t;
  while(t--)
    solve();
  return 0;
}
