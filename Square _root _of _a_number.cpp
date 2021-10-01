#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x);
long long int floorSqrt(long long int x) 
{
   if (x == 0 || x == 1)  
       return x; 
  
  // reference https://practice.geeksforgeeks.org/problems/square-root/1
   long long int s = 1, end = x, ans;    
    while (s <= end)  
    {         
    long long int mid = (s + end) / 2; 
  
        if (mid*mid == x) 
            return mid; 
  
  
        if (mid*mid < x)  
        { 
            s = mid + 1; 
            ans = mid; 
        }  
        else 
            end = mid-1;         
    } 
    return ans; 
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout << floorSqrt(n) << endl;
    }
    return 0;   
}
 
