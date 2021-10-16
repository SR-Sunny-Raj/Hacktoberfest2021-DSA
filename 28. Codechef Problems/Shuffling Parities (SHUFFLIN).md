>Problem Name : Shuffling Parities <br>
>Problem Code : SHUFFLIN <br>

## QUESTION LINK : https://www.codechef.com/SEPT21C/problems/SHUFFLIN

**Solution :**
```
#include <iostream>
using namespace std;

int main() 
{
    int tc; cin>>tc;
    while(tc--)
    {
        int n; cin>>n;
        
        int a, odd=0, even=0, i=0;
        while(i<n)
        {
            cin>>a;
            if(a%2==0) 
                even++;
            else 
                odd++;
            i++;
        }
        
        if(odd>=n/2) 
            cout<< n/2 + even <<'\n';
        else 
            cout<< odd + (n-n/2) <<'\n';
    }
    return 0;
}

```
