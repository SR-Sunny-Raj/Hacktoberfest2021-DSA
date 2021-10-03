#include <bits/stdc++.h>

using namespace std;

void balanced(int opening, int closing, string ans, vector<string>& v)
{
	if (opening == 0 && closing == 0)
	{
		v.push_back(ans);
		return;
	}
	if (opening == closing)
	{
		ans.push_back('(');
		balanced(opening - 1, closing, ans, v);
	}
	else if (opening < closing)
	{
		if (opening > 0)
		{
			ans.push_back('(');
			balanced(opening - 1, closing, ans, v);
		}
		if (closing > 0)
		{
			if (opening > 0)
				ans.pop_back();
			ans.push_back(')');
			balanced(opening, closing - 1, ans, v);
		}
	}
	else
	{
		if (closing > 0)
		{
			ans.push_back(')');
			balanced(opening, closing - 1, ans, v);
		}
		if (opening > 0)
		{
			if (closing > 0)
				ans.pop_back();
			ans.push_back('(');
			balanced(opening - 1, closing, ans, v);
		}
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> v;
	balanced(n, n, "", v);
	return v;
}

int main()
{
	int n;
	cin >> n;
	vector<string> ans = generateParenthesis(n);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
