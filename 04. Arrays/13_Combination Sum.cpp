/*
Problem statement:

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations.
The list must not contain the same combination twice, and the combinations may be returned in any order.


Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
Example 4:

Input: k = 3, n = 2
Output: []
Explanation: There are no valid combinations.
Example 5:

Input: k = 9, n = 45
Output: [[1,2,3,4,5,6,7,8,9]]
Explanation:
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
There are no other valid combinations.


Constraints:

2 <= k <= 9
1 <= n <= 60

*/


#include <iostream>
#include <vector>


vector<vector<int>> ans; // declared globally

void makesum(vector<int>& v, int tar, int ssf, vector<int> &temp, int idx, int cnt) {
	if (ssf > tar) {
		return;
	}
	if (ssf == tar) {
		if (cnt == 0) {
			ans.push_back(temp);
		}
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		temp.push_back(v[i]);
		makesum(v, tar, ssf + v[i], temp, i + 1, cnt - 1);
		temp.pop_back();
	}
}


vector<vector<int>> combinationSum3(int k, int n) {
	vector<int> temp;
	vector<int> candidates;
	for (int i = 0; i < 9; i++) {
		candidates.push_back(i + 1);
	}
	makesum(candidates, n, 0, temp, 0, k);
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n, k;

		combinationSum3(n, k);

		for (auto x : ans) {
			cout << x << " ";
		}

		cout << endl;
	}
	return 0;
}
