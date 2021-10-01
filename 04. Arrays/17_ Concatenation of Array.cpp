/*
Problem Statement:

Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.



Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]


Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000


*/

#include <bits/stdc++.h>
using namespace std;


vector<int> getConcatenation(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		nums.push_back(nums[i]);
	}
	return nums;
}



int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n ;
		cin >> n;

		vector<int> nums(n);

		for (int i = 0; i < n ; i++) {
			cin >> nums[i];
		}

		vector<int> res =  getConcatenation(nums);

		for (auto x : res) {
			cout << x << " ";
		}
		cout << endl;


	}
	return 0;
}
