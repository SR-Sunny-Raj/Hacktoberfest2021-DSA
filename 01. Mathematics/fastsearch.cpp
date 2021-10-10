#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main()
{
    IOS;
    int n,t;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cin>>t;
    while(t--)
    {
        int lower,higher,l1,u1;
        cin>>lower>>higher;
        int l=-1;
        int r = n;
        while(r>l+1)
        {
            int mid = l +(r-l)/2;
            if(arr[mid]<lower)
            {
                l = mid;
            }
            else
                r =mid;
        }
        l1 = l;
        l = -1;
        r = n;
        while(r>l+1)
        {
            int mid = l +(r-l)/2;
            if(arr[mid]<= higher)
                l = mid;
            else
                r = mid;

        }
        u1 = r;
        cout<<(u1-l1-1)<<endl;
        }



    return 0;
}
