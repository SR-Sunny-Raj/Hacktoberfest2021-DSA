#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    long int n = 1000000;
    bool is_prime[n+1];
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(long int i=2;i*i<=n;i++)
    {
        if(is_prime[i] == true)
        {
            for(long int j = 2*i;j<=n;j+=i)
            {
                is_prime[j] = false;
            }
        }

    }
    for(int u=1;u<=t;u++)
    {
        cout<<"Case "<<u<<": ";
        long int n;
        cin>>n;
        for(long int i=2;i<=n;i++)
        {
            if(is_prime[i]==true && n%i==0)
                cout<<i<<" ";
        }
        cout<<"\n";
    }



    return 0;
}
