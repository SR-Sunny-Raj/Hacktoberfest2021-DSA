/*

Problem Statement:

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/


#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
	int n = s.size();
	if (n == 0)
		return "";
	bool dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = true;

	string ans = "";
	ans += s[0];

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				if (j - i == 1 || dp[i + 1][j - 1])
				{
					dp[i][j] = true;
					if (ans.size() < j - i + 1)
						ans = s.substr(i, j - i + 1);
				}
			}
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		string s;
		cin >> s;
		cout << longestPalindrome(s) << endl;
	}
	return 0;
}
