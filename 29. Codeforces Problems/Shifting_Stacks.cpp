//CREATED SOLUTION FOR CODEFORCES PROBLEM :https://codeforces.com/contest/1486/problem/A



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL); 
int t; cin>>t;
while(t--){
    int n; cin>>n;
    ll sum=0;
    int p=0,need=0;
    for(int i=0;i<n;i++){
        ll a; cin>>a;
        need+=i;
        sum+=a;
        if(sum<need){
            p=1;
        }
    }
    if(p==0) cout<<"YES\n";
    else cout<<"NO\n";
}
return 0;
}
