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
        cin>>n;
        cin>>s>>st;
        char ok;
        cnt = 0;
        ll s_zero = 0, s_one = 0, st_zero = 0, st_one = 0;
        for(i=0;i<n;++i){
            if(s[i]==st[i]){
                if(s[i]=='1'){
                    if(s[i+1]=='0' and s[i+1]==st[i+1]){
                        cnt+=2;
                        ++i;
                    }
                    else{
                        cnt+=0;
                    }
                }
                else{
                    if(s[i+1]=='1' and s[i+1]==st[i+1]){
                        cnt+=2;
                        ++i;
                    }
                    else{
                        cnt++;
                    }
                }
            }
            else{
                cnt+=2;
            }
        }
        cout<<cnt<<endl;
    }


    return 0;
}
