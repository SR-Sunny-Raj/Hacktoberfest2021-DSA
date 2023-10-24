#include <bits/stdc++.h>
using namespace std;
#define int long long
double n;
bool good(double x)
{
    return((x*x*x*x + x )>=n);
}
int32_t main()
{

    cin>>n;
    double l=0; // l is bad
    double r = n+10;// r is good

    for(int i=0;i<100;i++)
    {
        double mid = l + (r-l)/2 ;
        if(good(mid))
        {
            r = mid;
        }else
        {
            l =mid;
        }
    }
    cout<<setprecision(20)<<r*r;

    return 0;
}
