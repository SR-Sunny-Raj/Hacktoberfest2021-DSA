#include <bits/stdc++.h>
using namespace std;

int main() {
    int q,n;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    
    while(q--)
     {
         int l,r,x,count=0;
         cin>>l>>r>>x;
         
        if(a[l-1]>=x && a[r-1]>=x)
        {
            count=r-l+1;
        }
        
        else if(a[(r-1)/2]<=x)
        { for(int i=r-1;i>=l-1;i--)
          {
             if(a[i]>=x)
               count++;
             else
               break;
    
          }
        }
        
        else if(a[(r-1)/2]>=x)
        { for(int i=l-1;i<=r-1;i++)
          {
             if(a[i]<x)
               count++;
             else
               break;
    
          }
          count=(r-l+1)-count;
        }
         
        cout<<count<<endl;
     }

	// your code goes here
	return 0;
}
