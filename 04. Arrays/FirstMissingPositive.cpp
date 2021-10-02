/*
FIRST MISSING POSITIVE INTEGER


Problem statement:
Given an unsorted integer array nums, return the smallest missing positive integer.

Example 1:

Input: nums = [1,2,0]
Output: 3

Example 2:

Input: nums = [3,4,-1,1]
Output: 2


Constraints:

1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1

*/

#include<bits/stdc++.h>
using namespace std;

//Function to find first Missing Positive Integer
int firstMissingPositive(vector<int>nums){
	int n=nums.size();
	for(int i=0;i<n;i++){
		while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
		swap(nums[i],nums[nums[i]-1]);
	}
	for(int i=0;i<n;i++){
		if(nums[i]!=i+1)
		return i+1;//We have Already Encountered the Number
	}
	return n+1;//The Array consists of numbers from 1 to n
}
int main(){
	std::ios::sync_with_stdio(false);
	cout<<"Enter the Number of elements in Array : ";
	int n;
	cin>>n;
	vector<int>nums;
	cout<<"Enter the Elements of the Array :";
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		nums.push_back(x);
	}
	int res=firstMissingPositive(nums);
	cout<<"The First Missing Positive Inetger is :"<<" "<<res<<endl;
}

/*

Time Complexity : O(n) , where n is the number of elements in Array
Space Complexity : O(1), No extra data Structure is being Used

*/
