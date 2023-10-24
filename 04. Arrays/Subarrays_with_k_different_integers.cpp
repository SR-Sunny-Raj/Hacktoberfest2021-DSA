/*
Problem : Given an integer array and an integer k, return the number of subarrays of given arrays having exactly k different integers.

Example: 
Input: n = 5 ,arr = [1,3,1,3,4] , k = 2
Output: 7

Explanation: subarrays with exactly 2 different integers are: [1,3] , [3,1] ,
 [1,3] , [3,4], [1,3,1], [3,1,3] , [1,3,1,3] 
*/

#include<bits/stdc++.h>
using namespace std;

int atleast(vector<int>&nums , int k)
{
  unordered_map<int,int>m;
  int diff = 0;
  int total = 0;
  int l = 0;
  int r = 0;
  int n = nums.size();
  for(;r<n;r++)
    {
      if(m[nums[r]] == 0)
	{
	  diff++;
	}
      m[nums[r]]++;
      if(diff<=k) 
	{
	  total+=(r-l+1);
	}
      else
	{
	  while(l<=r && diff > k)
	    {
	      m[nums[l]]--;
	      if(m[nums[l]] == 0)diff--;
	      l++;
	    }
	  total+=(r-l+1);
	}
    }
  return total;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
  return atleast(nums,k) - atleast(nums,k-1);
        
}
int main()
{
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;i++) cin>>nums[i];
  int k;
  cin>>k;

  cout<<subarraysWithKDistinct(nums,k);
  
}
