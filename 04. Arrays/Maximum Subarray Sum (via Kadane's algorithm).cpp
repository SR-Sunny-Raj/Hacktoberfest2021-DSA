//Maximum Subarray Sum (via Kadane's algorithm)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    int maxi=INT_MIN;
    for(i=0;i<n;i++)
    {
     sum=sum+arr[i];
     if(sum>=0)
     {
        maxi=max(maxi,sum); 
     }
     else if(sum<0)
     {
        sum=0;  
     }
     }
     cout<<"maximum subarray sum ="<<maxi;
     return 0;
} 
