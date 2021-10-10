#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int t;
    cin>>t;
    long long int n = 1000000000;
    bool is_prime[n+1];
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(long long int i=2;i*i<=n;i++)
    {
        if(is_prime[i] == true)
        {
            for(long long int j = 2*i;j<=n;j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
    while(t!=0)
    {
        long long int n,m;
        cin>>n>>m;
        for(long long int i =n ;i<= m ;i++)
        {
            if(is_prime[i])
                cout<<i<<"\n";
        }
        cout<<"\n";
        t--;
    }

    return 0;
}
