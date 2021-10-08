#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define lld long double
#define lli long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define INF 1e18
#define mod 1000000007
#include <string.h>

int main()
{
    FIO;
    ll t, a,b,n,m, k, i, j,cnt;
    cin>>t;
    string s,st;
    while(t--){
        cin>>n>>m;
        vector<ll> v(m);
        for(i=0;i<m;i++){
            cin>>v[i];
        }
        cnt = 0;
        for(i=1;i<m;i++){
            for(j=0;j<i;j++){
                if(v[i]>v[j]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;

    }


    return 0;
}
