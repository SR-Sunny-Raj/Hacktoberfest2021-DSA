/*
Problem Statement:

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int n = nums.size();
	sort(nums.begin() , nums.end());
	vector<vector<int>> ans;
	set<vector<int>> store;
	for (int i = 0 ; i < n; i++) {

		for (int j = i + 1; j < n ; j++) {

			int new_target  =  target - nums[i] - nums[j];

			int x = j + 1 , y = n - 1;

			while (x < y) {

				int sum = nums[x] + nums[y];

				if (sum > new_target) y--;
				else if (sum < new_target ) x++;
				else  {
					store.insert({nums[i] , nums[j] , nums[x] , nums[y]});
					x++;
					y--;
				};
			}
		}
	}

	for (auto i : store) {
		ans.push_back(i);
	}

	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		vector<int> nums(n);

		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		int target;
		cin >> target;

		vector<vector<int>> res;
		res = fourSum(nums, target);

		for (int i = 0; i < res.size(); i++) {
			for (int j = 0 ; j < res[i].size(); j++)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
