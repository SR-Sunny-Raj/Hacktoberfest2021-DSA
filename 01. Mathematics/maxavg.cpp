#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
long long n,d;
vector<double> arr;
vector<double>pre;
bool good(double x )
{

    pre[0] = 0;
    for(long long i=1;i<=n;i++)
        pre[i] = pre[i-1] + arr[i-1] -x;
    double mini = 0;
    for(long long r = d ; r<=n;r++)
    {
        if(mini > pre[r-d])
        {
            mini = pre[r-d];
        }
        if(mini <= pre[r])
        {
            return true;
        }
    }
    return false;

}



int32_t main()
{

    IOS;
    cin>>n>>d;
    arr.resize(n);
    pre.resize(n+1);
    for(int i=0 ; i<n;i++)
        cin>>arr[i];

    double l=0 ; // l is good
    double r = 1e8;// r is bad

    for(int i=0;i<100;i++)
    {
        double mid = l + (r-l)/2 ;
        if(good(mid))
        {
            l = mid;
        }else
        {
            r =mid;
        }
    }
    pre[0] = 0;
    for(int i=1;i<=n;i++)
        pre[i] = pre[i-1] + arr[i-1] - l;
    double mini = 0;
    int minind = 0;
    for(long long i = d ; i<=n;i++)
    {
        if(mini > pre[i-d])
        {
            mini = pre[i-d];
            minind = i -d;
        }
        if(mini <= pre[i])
        {
            cout<<minind+1<<" "<<i;
            break;
        }
    }







    return 0;
}
