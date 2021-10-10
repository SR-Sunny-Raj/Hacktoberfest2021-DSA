#include <bits/stdc++.h>
using namespace std;
#define int long long
long long m,n;
struct triplet
{
    long long t;
    long long z;
    long long y;
};
vector<triplet>arr;
bool good(long long timet)
{

    long long fans =0;
    for(long long i=0;i<n;i++)
    {
        fans += timet / (arr[i].t*arr[i].z + arr[i].y ) * arr[i].z + min( ( timet % (arr[i].t + arr[i].y )/arr[i].t ) , arr[i].z );
    }
    return fans>=m;
}

int32_t main()
{
    cin>>m>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].t>>arr[i].z>>arr[i].y;
    }
    if(m==0)
    {
        cout<<"0\n";
        for(int i =0;i<n;i++)
            cout<<"0  ";
        return 0;
    }

    int l=-1;
    int r = 1e7;
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
    int timet = r;
    int fans =0;
    int sum = 0;
    cout<<timet<<"\n";
    for(long long i=0;i<n-1;i++)
    {
        fans = timet / (arr[i].t*arr[i].z + arr[i].y ) * arr[i].z + min( ( timet % (arr[i].t + arr[i].y )/arr[i].t ) , arr[i].z );
        sum += fans;
        cout<<fans<<" ";
    }
    cout<<m -sum;


    return 0;
}
