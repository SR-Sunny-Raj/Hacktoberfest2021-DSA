/*
Problem Statement:

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.



Example 1:

Input: s = "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: s = "III"
Output: [0,1,2,3]
Example 3:

Input: s = "DDI"
Output: [3,2,0,1]


Constraints:

1 <= s.length <= 105
s[i] is either 'I' or 'D'.

*/


#include <bits/stdc++.h>
using namespace std;

vector<int> diStringMatch(string S) {

	vector<int> res;
	for (int l = 0, h = S.size(), i = 0; i <= S.size(); ++i)
		res.push_back(i == S.size() || S[i] == 'I' ? l++ : h--);
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		string s;

		cin >> s;
		vector<int> res = diStringMatch(s);

		for (auto x : res) {
			cout << x << " ";
		}
		cout << endl;


	}
	return 0;
}
