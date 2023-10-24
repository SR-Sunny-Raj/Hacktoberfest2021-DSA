#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
long check(long n ,long t)
{
    if(t == 0)
    return 1;
    if(t%2 == 0)
    return (check((n%m * n%m)%m,t/2))%m;
    else
    return (n%m * (check((n%m * n%m)%m,(t-1)/2))%m)%m;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    long ans = check(2,t);
    cout<<ans<<endl;
}
