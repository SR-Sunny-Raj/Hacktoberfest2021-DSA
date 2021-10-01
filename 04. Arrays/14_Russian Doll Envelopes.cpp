/*

Problem Statement:

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104

*/

#include <bits/stdc++.h>

using namespace std;


static bool compare(vector<int>&a , vector<int>& b)
{
	return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

int maxEnvelopes(vector<vector<int>>&a) {
	sort(a.begin(), a.end(), compare);
	vector<int>dp;
	for (auto i : a)
	{
		auto it = lower_bound(dp.begin(), dp.end(), i[1]);
		if (it == dp.end())
			dp.push_back(i[1]);
		else
			*it = i[1];
	}
	return dp.size();
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
		vector<vector<int> > nums(n, vector<int>(m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> nums[i][j];
			}
		}

		cout << maxEnvelopes(nums) << endl;
	}
	return 0;
}
