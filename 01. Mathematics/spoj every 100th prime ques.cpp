#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin>>n;
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
    long long counts =0;
    for(long long int i=0;i<= n ; i++)
    {
        if(is_prime[i]== true)
        {
            counts++;
            if(counts%100 == 1)
                cout<<i<<"\n";
        }
    }


    return 0;
}
