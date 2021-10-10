#include <bits/stdc++.h>
using namespace std;
#define int long long
long long x,y,n;
bool good(long long w)
{
    w = w -min(x,y);
    return ((w/x) + (w/y) >= n-1);

}
int32_t main()
{
    cin>>n>>x>>y;
    int l=0; // l is bad
    int r = n*max(x,y) + 5 ;// r is good
    if(n==1)
    {
        cout<<min(x,y);
    }
    else if(n==2)
    {
        cout<<2*min(x,y);
    }
    else
    {
        while(r>l+1)
        {
            int mid_val = l + (r-l)/2 ;
            if(good(mid_val))
            {
                r = mid_val;
            }else
            {
                l =mid_val;
            }
        }
        cout<<r;
    }
    return 0;
}
