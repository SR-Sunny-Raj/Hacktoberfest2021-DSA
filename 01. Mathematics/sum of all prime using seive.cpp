#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int n;
    cin>>n;
    bool is_prime[n+1];
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(long int i=2;i*i<= n ; i++)
    {
       if(is_prime[i]== true)
       {
           for(long long int j = 2*i;j<= n;j+=i)
           {
               is_prime[j] = false;
           }
       }

    }
    vector<int>prime;
    for(long int i=2;i<n;i++)
    {
        if(is_prime[i]==true)
            prime.push_back(i);
    }
    long int sum = 0;
    for(long int i = 0 ; i<prime.size();i++)
    {
        if(n%prime[i]==0)
            sum+= prime[i];
    }
    cout<<"\n"<<prime.size();

    return 0;
}

