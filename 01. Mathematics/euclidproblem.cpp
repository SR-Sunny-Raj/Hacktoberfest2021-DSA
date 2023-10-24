#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
long long MOD = 1e9 + 7;

long long gcd(long long a , long long b , long long& x , long long& y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1,y1;
    long long d = gcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int32_t main()
{
    IOS;
    int a,b,x,y,ans;
    while(scanf("%lld %lld", &a, &b) == 2)
    {
        ans = gcd(a,b,x,y);
        cout<<x<<" "<<y<<" "<<ans<<"\n";
    }




    return 0;
}
