#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    map<long long, long long> mp, hash;
    for(long long int i = 0; i < n-1; i++)
    {
        cin>>mp[i];
        hash[mp[i]] = 1;
    }
    for(long long int i = 1; i <= n; i++)
    {
        if(hash[i] == 0)
        {
            cout<<i<<endl;
            break;
        }
    }
}
