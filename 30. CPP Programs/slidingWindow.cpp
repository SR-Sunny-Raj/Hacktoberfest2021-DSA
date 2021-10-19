#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
	int start = 0;
	int currSum = 0;
	int minlen = INT_MAX;
	int ans = 0;

	// sliding window
	for (int i = 0; i < nums.size(); i++)
	{
		currSum += nums[i];
		while (currSum >= target)
		{
			ans = min(minlen, i - start + 1);
			minlen = ans;
			currSum -= nums[start];
			start++;
		}
	}
	return ans;
}

int main()
{
	vector<int> val{1, 4, 5, 6, 7, 8, 4, 3, 5, 9};
	minSubArrayLen(15, val);
}
