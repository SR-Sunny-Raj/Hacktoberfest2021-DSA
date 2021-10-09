#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll  long long int
using namespace __gnu_pbds;
using namespace std;

#define test   ll T;cin >> T;while (T--)
#define f(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
 
int main()
{
    
   ll n,k;
   cin>>n>>k;
   ll a[n];
   f(i,0,n)
   cin>>a[i];

   ll ans;
 
   ll lo=0,hi=1e18,ma=0;
   while(lo<=hi)
   {
       ll mid=(lo+hi)/2;
       ll i=0,ctr=1,s=0,ma=0;
       while(i<n)
       {
           if((s+a[i])<=mid)
           s+=a[i];
           else
           {
                ma=max(ma,s);
               s=a[i];
               ctr++;
           }
           i++;
       }
       ma=max(ma,s);
        if(ctr<k){
      //  ans=mid;
        hi=mid-1;}
        else if(ctr==k)
        {
            ans=ma;
            hi=mid-1;
        }
        else
        {
          //  ans=mid;
            lo=mid+1;
        }
   }
 
    cout<<ans<<"\n";
 
 
 
cerr << "Time Elapsed : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
   return 0;
 
}
