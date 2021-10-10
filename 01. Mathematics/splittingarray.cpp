#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
long long n,k;
vector<long long> arr;
long long maxi;
bool good(long long x)
{
    long long noseg =0;
    long long temp =0;
    if(x<maxi)
        return false;
    for(long long i =0;i<n;i++)
    {
        temp += arr[i];
        if(temp>x)
        {
            temp =arr[i];
            noseg++;

        }
        else if(temp == x)
        {
            temp =0;
            noseg++;
        }
    }
    if(temp!=0)
        noseg++;
    return noseg<=k;
}

int32_t main()
{
    IOS;
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    maxi = *max_element(arr.begin(),arr.end());
    int l= 0; // l is bad
    int r = 1 ;// r is good
    while(!good(r))
        r = 2*r;
    while(r>l+1)
    {
        int mid = l + (r-l)/2 ;
        if(good(mid))
        {
            r = mid;
        }else
        {
            l =mid;
        }
    }
    cout<<r;

    return 0;
}
