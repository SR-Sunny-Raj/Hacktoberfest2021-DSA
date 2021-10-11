// Problem link : https://www.codechef.com/problems/CHFINVNT

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){

        ll n,p,k;
        cin>>n>>p>>k;

        ll ans = 0;

        ll rem = p%k;

        ll times = n/k;

        ans += rem*times;
        ans += p/k;
        ans += min(rem,n%k);        
        
        cout<<ans+1<<endl;
    } 
    
    return 0;
}
