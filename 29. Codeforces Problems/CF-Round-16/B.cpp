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
        cin>>s;
        cnt = 0;
        char ok = s[0];
        for(i=1;i<s.size();i++){
            if(ok!=s[i]){
                if(ok=='0'){
                    cnt++;
                }
                ok = s[i];
            }

            if(cnt>1){
                cnt = 2;
                break;
            }
        }
        if(cnt<2){
                if(ok=='0'){
                    cnt++;
                }
        }
        cout<<cnt<<endl;

    }


    return 0;
}
