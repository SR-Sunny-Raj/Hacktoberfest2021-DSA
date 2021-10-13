// https://codeforces.com/contest/1516/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> pre_xor(n+1);
    pre_xor[0] = 0;
    for(int i=1; i<=n; i++){
        int a; cin>>a;
        pre_xor[i] = pre_xor[i-1]^a;
    }
    if(pre_xor[n]==0){
        cout << "YES" << endl;
        return;
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<n; j++){
            int xor1 = pre_xor[i];
            int xor2 = pre_xor[j]^pre_xor[i];
            int xor3 = pre_xor[n]^pre_xor[j];
            if(xor1==xor2 && xor2==xor3){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}