// https://codeforces.com/contest/1513/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) arr[i]=i+1;
    int invertible_pairs = (n-1)/2;
    if(invertible_pairs < k){
        cout << -1 << endl;
        return;
    }
    sort(arr.begin(), arr.end());
    int i = 1;
    while(k--){
        swap(arr[i], arr[i+1]);
        i+=2;
    }
    for(auto ele : arr) cout << ele << " "; cout << endl;
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