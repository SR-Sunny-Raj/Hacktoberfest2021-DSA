#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
long long MOD = 1e9 + 7;
long long n,k;
vector<long long>arr;
bool good(double x){
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        s += arr[i]/x;
    }
    return s>=k;
}

int32_t main()
{
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    double l=0; //l is good
    double r = 2; // r is bad
    while(good(r))
        r *=2;

    for(int i=0;i<100;i++)
    {
        double mid_val = l +(r-l)/2;
        if(good(mid_val)){
            l = mid_val;
        }else{
            r =mid_val ;
        }
    }
    cout<<setprecision(20)<<l;
    return 0;
}
