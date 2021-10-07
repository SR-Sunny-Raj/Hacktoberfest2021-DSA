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
    string s;
    while(t--){
        ll n;
        cin>>n;
        cin>>m;
        ll ans = ceil((double)n/2);
        n-=(ans-1);
        cout<<m/n<<endl;

    }


    return 0;
}
