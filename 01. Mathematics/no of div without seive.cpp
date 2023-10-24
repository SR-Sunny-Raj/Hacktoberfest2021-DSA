#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int result;
    cin>>result;
    long int ans =0;
    for(long int i=1;i*i<=result;i++)
    {
        if(result%i==0)
        {
            if(i*i == result)
                ans++;
            else
                ans+=2 ;
        }
    }
    cout<<ans;





    return 0;
}

