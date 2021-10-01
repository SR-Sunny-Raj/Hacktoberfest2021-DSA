/*

Problem Statement:

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1

*/


#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
	// Moore voting algorithm
	int counter = 0, majority;
	for (int num : nums) {
		if (!counter) {
			majority = num;
		}
		counter += num == majority ? 1 : -1;
	}
	return majority;
}


int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		cout << majorityElement(nums) << endl;

	}
	return 0;
}
