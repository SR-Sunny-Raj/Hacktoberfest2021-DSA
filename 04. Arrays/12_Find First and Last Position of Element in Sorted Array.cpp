/*
Problem statement:
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109


*/
#include "bits/stdc++.h"
#define endl "\n"

using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
	int start = -1;
	int end = -1;
	int low = 0, high = int(nums.size()) - 1;
	while (low <= high) {

		int mid = (high + low) / 2;

		if (nums[mid] == target) {
			// intially consider the mid is the starting and end position
			start = mid;
			end = mid;

			// now we will search in left and right search for new start and end positions
			int tempLow = low;
			int tempHigh = mid - 1;

			// find " new START " in left subarray
			while (tempLow <= tempHigh) {

				int tempMid = (tempLow + tempHigh) / 2;

				if (nums[tempMid] == target) {

					start = tempMid;
					tempHigh = tempMid - 1;

				} else {

					tempLow = tempMid + 1;

				}
			}

			// find " new END " in right subarray
			tempLow = mid + 1;
			tempHigh = high;
			while (tempLow <= tempHigh) {
				int tempMid = (tempLow + tempHigh) / 2;
				if (nums[tempMid] == target) {
					end = tempMid;
					tempLow = tempMid + 1;
				} else {
					tempHigh = tempMid - 1;
				}
			}

			// important step to follow
			// =========
			break;
			// =========
		}

		if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	nums.clear();

	return {start, end};
}


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		vector<int> nums(N);
		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			nums.push_back(x);
		}
		int target;
		cin >> target;
		vector<int> ans = searchRange(nums, target);
		cout << "[";
		for (auto x : ans) {
			cout << x << ", ";
		}
		cout << "]" << endl;

	}
}  // } Driver Code Ends
