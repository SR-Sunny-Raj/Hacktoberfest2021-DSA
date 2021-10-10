#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
long long MOD = 1e9 + 7;
int32_t main()
{
    IOS;
    int n,t;
    cin>>n>>t;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(t--)
    {
        int val;
        cin>>val;
        int l = -1;
        int r = n;
        while(r>l+1)
        {
            int mid = l +(r-l)/2;
            if(val>=a[mid])
                l = mid;
            else
                r = mid;
        }
        if(l>-1 && a[l]==val)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }



    return 0;
}
