/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.

Leetcode Problem Link: https://leetcode.com/problems/3sum-closest/
*/

//C++ Implementation
#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& a, int t) {
    sort(a.begin(),a.end());
    int n=a.size(), ans, d=INT_MAX;
    for(int i=0; i<n; i++){
        int l=i+1, r=n-1;
        while(r>l){
            int x=a[l]+a[i]+a[r];
            if(d>abs(x-t)) {d=abs(x-t); ans=x;}
            if(x==t) return x;
            if(x>t) r--;
            if(x<t) l++;
         }
    }
    return ans;
}

int main(){
  //size of array
  int n; cin>>n;
  
	vector<int> nums(n); //array of elements
  
  for(int i=0; i<n; i++){cin>>nums[i];}
  
  int target; cin>>target;
  
  cout<<"The sum of 3 integers, closest to target is: "<<threeSumClosest(nums, target);
  
	return 0;
}
