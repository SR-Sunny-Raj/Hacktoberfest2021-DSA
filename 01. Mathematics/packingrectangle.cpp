#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
long long w,h,n;
bool good(long long x)
{
    return (floor(x/w) * floor(x/h) >=n);
}
int32_t main()
{
    cin>>w>>h>>n;
    int l=0;
    int r = 2;
    while(!good(r))
        r *= 2;
    while(r>l+1)
    {
        int mid_val = l +(r-l)/2;
        if(good(mid_val)){
            r = mid_val;
        }else{
            l =mid_val;
        }
    }
    cout<<r;
    return 0;
}
