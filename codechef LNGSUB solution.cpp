//please accept this as hacktoberfest-accepted label
//problem link
//https://www.codechef.com/LTIME99B/problems/LNGSUB/
//thanks
//HAPPY CODING


#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ld long double
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define err() cout<<"--------------------------"<<endl; 
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl



#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second

#define pii pair<int,int>
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"

ll binaryexp(ll a,ll b,ll i)
{
    if(b==0)
        return 1LL;
    if(b==1)
        return a;
    ll k=binaryexp(a,b/2,i);
    if(b&1)
    {
        return (((k*k)%i)*a)%i;
    }
    else
        return (k*k)%i;
}
int LCSubStr(string X, string Y)
{
    int m=X.length();
    int n=Y.length();
 
    int LCSuff[m + 1][n + 1];
    int result = 0; 
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
int find(int i,V &par)
{
    if(par[i]==-1)
    {
        return i;
    }
    // return par[i];
    return find(par[i],par);
}
void make_pa(int i,int j,V &par)
{
    int x=find(i,par);
    int y=find(j,par);
    par[x]=y;
}
int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        #ifndef ONLINE_JUDGE
         clock_t tStart = clock();
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        int t;
        cin>>t;
        // t=1;
           
        while(t--)
        {
            int n;
            cin>>n;
            vector<string> v(n);
            rep(i,0,n)
            {
                cin>>v[i];
            }
            V vis(n+1,0);
            V par(n+1,-1);
            priority_queue<pair<int,pair<int,int>>> edge;
            rep(i,0,n)
            {
                rep(j,i+1,n)
                {
                   edge.push({LCSubStr(v[i],v[j]),{i,j}});
                }
            }
            ll s=0;
            while(! edge.empty())
            {
                pair<int,pair<int,int>> pp=edge.top();
                edge.pop();
                // err1(pp.ft);
                if(find(pp.sd.sd,par)!=find(pp.sd.ft,par))
                {
                    s+=pp.ft;
                    make_pa(pp.sd.sd,pp.sd.ft,par);
                }
            }
            cout<<s<<"\n";



        }
        #ifndef ONLINE_JUDGE
            printf("\nRun Time -> %.10fs\n", (double)(clock()-tStart) / CLOCKS_PER_SEC);
            #endif
} 
