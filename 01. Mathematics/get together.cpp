#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
long long n;
vector<long long > pos;
vector<long long > speed;
bool good(double t)
{
    double lmax =pos[0] - speed[0]*t;
    double rmin = pos[0] + speed[0]*t;
    for(int i=1;i<n;i++)
    {
        double temp1 = pos[i] - speed[i]*t;
        double temp2 = pos[i] + speed[i]*t;
        if(rmin>temp2)
            rmin = temp2;
        if(lmax<temp1)
            lmax =temp1;
    }
    return(rmin - lmax > 1e-7);
}

int32_t main()
{
    IOS;
    cin>>n;
    pos.resize(n);
    speed.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>pos[i];
        cin>>speed[i];
    }
    double l= 0; // l is bad
    double r =1e9;// r is good
    //binary for t
    for(int i=0;i<100;i++)
    {
        double mid = l + (r-l)/2 ;
        if(good(mid))
        {
            r = mid;
        }
        else
        {
            l =mid;
        }
    }
    cout<<setprecision(20)<<fixed<<r;

    return 0;
}
