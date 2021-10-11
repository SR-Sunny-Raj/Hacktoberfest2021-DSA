// Problem Link : https://www.codechef.com/MAY21C/problems/MODEQ

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
       ll n,m;
       cin>>n>>m;
       ll sum = 0;
       vector<ll> cnt(n+1,1);

       for(ll b = 2 ; b <= n ; b++){
           ll i = m%b;
           sum += cnt[i];
           for(ll j = i ; j <= n; j+=b){
               cnt[j]++;
           }     
        }

       cout<<sum<<"\n";            
    }

    return 0;
}