#include <bits/stdc++.h>
using namespace std;
#define int long long
string given;
string tofind;
string temp;
vector<long long>arr;
vector<string>sol;

bool good(long long x)
{
    int a[tofind.length()];
    for(long long i=0;i<tofind.length();i++)
        a[i] =0;
    int w=0;
    string tem = sol[x];
    for(long long i=0;i<tofind.length();i++)
    {
        for(long long j=w;j<tem.length();j++)
        {
            if(tem[j]!='_' && tofind[i]== tem[j])
            {
                    a[i] =1;
                    w =j+1;
                    break;
            }
        }
    }
    for(long long i=0;i<tofind.length();i++)
    {
        if(a[i]==0)
        {
            return false;
        }
    }
    return true;
}
int32_t main()
{

    cin>>given>>tofind;
    arr.resize(given.length());
    for(int i=0;i<given.length();i++)
    {
        int x;
        cin>>x;
        arr[i] =x-1;
    }
    temp = given;
    sol.resize(given.length() - tofind.length());
    for(int i=0;i<(given.length() - tofind.length());i++)
    {
        temp.at(arr[i]) = '_';
        sol[i] = temp;
    }
    int l=-1; // l is 1
    int r =given.length() - tofind.length()+1;// r is 0

    while(r>l+1)
    {
        int mid = l + (r-l)/2 ;
        if(good(mid))
        {
            l =mid;
        }
        else
        {
            r =mid;
        }
    }
    cout<<l+1;








    return 0;
}
