#include <bits/stdc++.h>
using namespace std;
bool containzero(long int n)
{
    bool ans =false;
    while(n>0)
    {
        if(n%10 == 0)
        {
            ans = true;
            break;
        }
        n/=10;
    }
}
vector<int> primewithoutzero()
{
    long int n = 1000000;
    bool is_prime[n+1];
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    vector<int> primearr;
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
    for(long int i=2;i<=n ; i++)
    {
        if(is_prime[i]==true )
        {
            if(containzero(i)== false)
                primearr.push_back(i);
        }

    }
    return primearr;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> primearr = primewithoutzero();
    long int t;
    cin>>t;
    while(t!=0)
    {
        long int n;
        cin>>n;
        int ans =0;
        int i=0;
        while(primearr[i]<= n)
        {
            ans++;
            i++;
        }
        cout<<ans<<"\n";
        t--;
    }




    return 0;
}


