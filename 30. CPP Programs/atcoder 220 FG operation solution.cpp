
//problem link
//https://atcoder.jp/contests/abc220/tasks/abc220_d
//atcoder 220 FG operations solution
//                                                     /*    please accept it as hacktoberfest-accepted label   */
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
        // cin>>t;
        t=1;
           
        while(t--)
        {
            ll n;
            cin>>n;
            V a(n);
            rep(i,0,n)
            {
                cin>>a[i];
            }
            // vector<VV> dp(2,VV(n,V(10,0)));
            VV dp(n,V(10,0));
            //func , i, dig

            rep(i,1,n)
            {
                if(i==1)
                {
                    dp[i][(a[i]+a[i-1])%10]+=1;
                    dp[i][(a[i]*a[i-1])%10]+=1;
                }  
                else
                {
                    rep(j,0,10)
                    {
                        dp[i][(j+a[i])%10]+=dp[i-1][j];
                        dp[i][(j*a[i])%10]+=dp[i-1][j];
                        dp[i][(j+a[i])%10]%=998244353;
                        dp[i][(j*a[i])%10]%=998244353;
                    }
                }
            }
            
            rep(i,0,10)
            {
                
                cout<<dp[n-1][i]<<"\n";
            }

        }
        #ifndef ONLINE_JUDGE
            printf("\nRun Time -> %.10fs\n", (double)(clock()-tStart) / CLOCKS_PER_SEC);
            #endif
} 
