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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int t;
    cin>>t;
    long int n = 100;
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
    vector<int> ans;
    short int temp =0;
    for(long int i=2;i<=100;i++)
    {
            if(is_prime[i] == true)
            {
                if(containzero(is_prime[i]== false))
                {
                    string s = to_string(i);
                    for(int j =0 ;j< s.length();j++)
                    {
                        s.erase(0,0);
                        int x = stoi(s);
                        if(is_prime[x] == false)
                        {
                            temp = 1;
                            break;
                        }

                    }
                    if(temp ==0)
                        ans.push_back(i);
                }
            }
    }
    while(t!=0)
    {
        long int counts = 0;
        long int n;
        cin>>n;
        int i=0;
        while(ans[i]<=n)
        {
            counts++;
            i++;
        }
        cout<<counts<<"\n";


        t--;
    }



    return 0;
}
