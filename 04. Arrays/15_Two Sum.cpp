/*
Problem Statement:

Given an array of  integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

*/



#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> indices;
	for (int i = 0; i < nums.size(); i++) {
		if (indices.find(target - nums[i]) != indices.end()) {
			return {indices[target - nums[i]], i};
		}
		indices[nums[i]] = i;
	}
	return {};
}


int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{

		int n,a;
		a=0;
		cin >> n;
		std::vector<int> nums(n);
		if(a==1)
		{
			return;
		}
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		int target;
		cin >> target;

		vector<int> res = twoSum(nums, target);

		for (auto x : res) {
			cout << x << " ";
		}
		cout << endl;

	}
	return 0;
}


/*

Another approach for this problem is "TWO POINTER APPROACH" which has the time complexity of O(n). 

Now let’s see how the two-pointer technique works. We take two pointers,one representing the first element and other
representing the last element of the array, and then we add the values kept at both the pointers. If their sum is 
smaller than X then we shift the left pointer to right or if their sum is greater than X then we shift the right pointer
to left, in order to get closer to the sum. We keep moving the pointers until we get the sum as X. 

*/
