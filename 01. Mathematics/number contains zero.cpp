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
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    bool ans = containzero(n);
    cout<<ans;




    return 0;
}
