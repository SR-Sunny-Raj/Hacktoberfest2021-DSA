// problem Link: https://cses.fi/problemset/task/1072
#include<bits/stdc++.h>
using namespace std;
long long calc(long n)
{
    long long a = (n*n)*((n*n)-1);
    a = a/2;
    long long b = 4*(n-1)*(n-2);
    return (a-b);
}
int main()
{
    long long int n;
    cin>>n;
    for(long long i = 1; i <= n; i++)
   {
       long long ans = calc(i);
        cout<<ans<<endl;
    }
}
