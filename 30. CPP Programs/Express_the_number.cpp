//Given two integers n and x, we want to express n as a sum of k integers n = A[1] + A[2] + A[3] + ... + A[k] satisfying the following:

//Either 0 ≤ A[1] ≤ x, or A[1] is an odd power of 2. The odd powers of 2 are 21, 23, 25, etc.
//All the other A[i]s are odd powers of 2 for 2 ≤ i ≤ k.

//Find the minimum possible value of k, or print -1 if we can't express n in the specified format



#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long 
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define REP(i,n) for(int i=0;i<n;i++)
#define w(t) int t; cin>>t; while(t--)
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

using namespace std;

int main(){
    fast; 
    int t;cin>>t;
	ll powersOf2[16];
    for(ll i=0; i<16; i++)
    {
        powersOf2[i]=pow(2,(2*i)+1);
    }
	while(t--){
        ll n,x; cin>>n>>x; int flag=0;
		if(x>=n) cout<<"1\n";
		else{
			ll ans=0;
		   for(int i=15; i>=0; i--)
        {
            if(powersOf2[i]<=n)
            {
                while((n- powersOf2[i])>=0)
                {
                    n-=powersOf2[i];
                    ans++;
                    if(n<=x) 
                    {flag = 1; break;}
                }
                if(flag==1) break;
            }}
			
			
			
			
				if(n==0){
					cout<<ans<<"\n";
				}
				else if(n<=x){
				   cout<<ans+1<<"\n";
				  // break;
				}
				else {
					cout<<"-1\n";
					//break;
				}
				
		}
    }
}
