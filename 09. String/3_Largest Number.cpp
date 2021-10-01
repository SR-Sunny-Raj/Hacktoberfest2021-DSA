/*
Problem statement:

Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.



Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
Example 3:

Input: nums = [1]
Output: "1"
Example 4:

Input: nums = [10]
Output: "10"


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109

*/

#include "bits/stdc++.h"
#define endl "\n"

using namespace std;

string largestNumber(vector<int> &num) {
	vector<string> arr;
	for (auto i : num)
		arr.push_back(to_string(i));
	sort(begin(arr), end(arr), [](string & s1, string & s2) { return s1 + s2 > s2 + s1; });
	string res;
	for (auto s : arr)
		res += s;
	while (res[0] == '0' && res.length() > 1)
		res.erase(0, 1);
	return  res;
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

		cout << largestNumber(nums) << endl;


	}
}  // } Driver Code Ends