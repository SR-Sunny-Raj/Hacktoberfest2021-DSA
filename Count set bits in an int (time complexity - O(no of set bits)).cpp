#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n)
    {
        n=n&(n-1); // this statement reset the last set bit in n
                    // 5 = 101(binary) after one loop n = 4 = (100)(binary). 
        ans++;
    }
    cout<<ans<<endl;
}