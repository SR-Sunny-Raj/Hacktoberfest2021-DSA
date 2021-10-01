/*
Problem Statement:

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000


*/

#include <bits/stdc++.h>

using namespace std;

string convert(string s, int nRows) {
	if (nRows <= 1) return s;
	string result = "";
	//the size of a cycle(period)
	int cycle = 2 * nRows - 2;
	for (int i = 0; i < nRows; ++i)
	{
		for (int j = i; j < s.length(); j = j + cycle) {
			result = result + s[j];
			int secondJ = (j - i) + cycle - i;
			if (i != 0 && i != nRows - 1 && secondJ < s.length())
				result = result + s[secondJ];
		}
	}
	return result;
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
		int numRows;
		cin >> numRows;

		cout << convert(s, numRows) << endl;
	}
	return 0;
}
