#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
    ll t;cin>>t;

    while(t--){
        ll A,B;
        cin>>A>>B;

        ll M=3;
        if (A % M == 0)cout<<(B / M) - (A / M) + 1<<endl;
        else cout<<(B / M) - (A / M)<<endl;
    }
    return 0;
}
