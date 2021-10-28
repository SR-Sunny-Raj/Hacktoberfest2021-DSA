#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        // Taking input of array
    }
    /*
      We start iterating from 1st index of array taking it as a key and increamenting it we compare key-1 index on left of that array and swap as we get a element bigger than our current key.
      As we get a element which is bigger than our cuurent key we will break our nested loop so basically observing what we are doing as we move forward we are sorting all the elements of the 
      array which are before our key element the tem variable in the below code is used because after every swap the position of our key would have been changed.
      
      Time Complexity of Insertion Sort- O(N^2)
      This is a algorithm of Inplace Sorting.
      In-place sorting means sorting without any extra space requirement.  In-place algorithm is an algorithm which transforms input using a data structure with a small,
      constant amount of extra storage space.
    */
    for(int i=1;i<n;i++)
    {
        ll tem=i,j=i-1;
        while(a[tem]<=a[j] && j>=0)
        {
            std::swap(a[tem],a[j]);
            tem--;
            j--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
