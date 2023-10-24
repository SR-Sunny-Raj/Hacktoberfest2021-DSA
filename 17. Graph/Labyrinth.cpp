#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define onesbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define sp(x, y) fixed << setprecision(y) << x
#define w(x)  int x;cin >> x;while (x--)
#define tk(x) int x;cin >> x;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x <<" ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif
template <class T> void _print(T t){cerr<<t;}
template <class T> void _print(vector < vector <T> > v){cerr<<"[\n";for(int l=0;l<v.size();l++){{for(int k=0;k<v[l].size();k++)cerr<<v[l][k]<<" ";}cerr<<"\n";}cerr<<"]";}

queue<pair<int,int>>que;
vector<vector<int>>vx;
vector<vector<int>>vy;
vector<vector<int>>dis;
int c=0,len=0;
void bfs(int i,int j,int n,int m,vector<vector<char>>& v,int l,vector<vector<bool>>& vis){
    vis[i][j]=true;
    if(i+1<n){
        if(v[i+1][j]=='.' && vis[i+1][j]==false) {
            vis[i+1][j]=true;
            dis[i+1][j]=dis[i][j]+1;
            vx[i+1][j]=i;
            vy[i+1][j]=j;
            que.push(mp(i+1,j));
        }
        else if(v[i+1][j]=='B'){
             dis[i+1][j]=dis[i][j]+1;
             vx[i+1][j]=i;
             vy[i+1][j]=j;
            c=1;
            cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
            return;
        }
    }
     if(j+1<m){
        
         if(v[i][j+1]=='.' && vis[i][j+1]==false){
             vis[i][j+1]=true;
             dis[i][j+1]=dis[i][j]+1;
             vx[i][j+1]=i;
             vy[i][j+1]=j;
             que.push(mp(i,j+1));
         }
         else if(v[i][j+1]=='B'){
            dis[i][j+1]=dis[i][j]+1;
            c=1;
             vx[i][j+1]=i;
             vy[i][j+1]=j;
             cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
            return;
        }
     }
     if(i-1>=0){
          
         if(v[i-1][j]=='.' && vis[i-1][j]==false){
             vis[i-1][j]=true;
             dis[i-1][j]=dis[i][j]+1;
             vx[i-1][j]=i;
             vy[i-1][j]=j;
             que.push(mp(i-1,j));
         }
         else if(v[i-1][j]=='B'){
             dis[i-1][j]=dis[i][j]+1;
             vx[i-1][j]=i;
             vy[i-1][j]=j;
            c=1;
            cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
            return;
        }
     }
     if(j-1>=0){
        
         if(v[i][j-1]=='.' && vis[i][j-1]==false){
             vis[i][j-1]=true;
             dis[i][j-1]=dis[i][j]+1;
            vx[i][j-1]=i;
            vy[i][j-1]=j;
             que.push(mp(i,j-1));
         }
         else if(v[i][j-1]=='B'){
             dis[i][j-1]=dis[i][j]+1;
            vx[i][j-1]=i;
            vy[i][j-1]=j;
            c=1;
            cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
            return;
        }
     }
}
int32_t main(){
fast


#ifndef ONLINE_JUDGE


    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);


#endif


int n,m;
cin>>n>>m;
vector<vector<bool>>vis(n,vector<bool>(m,false));
vector<vector<char>>v(n,vector<char>(m));
dis.resize(n);
vx.resize(n);
vy.resize(n);
int x,y,x1,y1;
for(int i=0;i<n;i++){
    dis[i].resize(m,0);
    vx[i].resize(m,0);
    vy[i].resize(m,0);
   for(int j=0;j<m;j++){
      cin>>v[i][j];
      if(v[i][j]=='A'){
          x=i;
          y=j;
      }
      else if(v[i][j]=='B'){
          x1=i;
          y1=j;
      }
   }
}
//cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
que.push(mp(x,y));
while(!que.empty()){
    x=que.front().first;
    y=que.front().second;
    que.pop();
   // debug(dis);
    len++;
    bfs(x,y,n,m,v,len,vis);
    if(c==1){
        break;
    }
}
  
int distance=dis[x1][y1];
int z=distance;
string ans="";
while(distance--){
    int px=vx[x1][y1];
    int py=vy[x1][y1];
    if(x1-1==px){
        ans+="D";
        x1=x1-1;
    }
    else if(x1+1==px){
         ans+="U";
         x1=x1+1;
    }
    else if(y1-1==py) {
        ans+="R";
        y1=y1-1;
    }
    else if(y1+1==py) {
        ans+="L";
        y1=y1+1;
    }
    
}

reverse(ans.begin(),ans.end());
 
 if(z==0){
     cout<<"NO"<<"\n";
 }
 else{
      cout<<"YES"<<"\n"<<z<<"\n"<<ans<<"\n";
 }
// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  
return 0;
}
