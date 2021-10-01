/*
Problem Statement:

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/


#include <bits/stdc++.h>
#include <cstdio>


using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

	vector<int> res;

	for (auto x : nums1) {
		if (find(nums2.begin(), nums2.end(), x) != nums2.end()) {
			if (find(res.begin(), res.end(), x) == res.end()) {
				res.push_back(x);
				continue;
			}
		}
	}



	return res;

}


int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> nums1(n);
		vector<int> nums2(m);

		for (int i  = 0;  i < n; i++) {
			cin >> nums1[i];
		}

		for (int i  = 0;  i < m; i++) {
			cin >> nums2[i];
		}

		std::vector<int> res = intersection(nums1, nums2);

		for (auto x : res) {
			cout << x << " ";
		}

		cout << endl;

	}
	return 0;
}
