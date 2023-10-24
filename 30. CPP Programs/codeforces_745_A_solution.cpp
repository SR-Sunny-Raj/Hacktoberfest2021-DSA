//manish kumar patel
//codeforces round 745 A solution
//problem link
//  https://codeforces.com/contest/1581/problem/A
// please merge this as hacktoberfest-accepted label
//thanks

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
        ll fact[200005];
        fact[0]=1;
        rep(i,1,200005)
        {
            fact[i]=(fact[i-1]*i)%1000000007;
        }
        while(t--)
        {
            
            ll n;
            cin>>n;
            cout<<(fact[2*n]*binaryexp(2,1000000005,1000000007))%1000000007<<"\n";

        }
        #ifndef ONLINE_JUDGE
            printf("\nRun Time -> %.10fs\n", (double)(clock()-tStart) / CLOCKS_PER_SEC);
            #endif
} 
