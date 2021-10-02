#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution
{
public:
  int minCoinsChange(int N, vector<int> coins, int target)
  {
    int dp[100] = {0};

    // iterate over all states
    for (int n = 1; n <= N; n++)
    {
      // init current array as INT_MAX
      dp[n] = INT_MAX;
      for (int i = 0; i < target; i++)
      {
        if (n - coins[i] >= 0)
        {
          int subProb = dp[n - coins[i]];
          dp[n] = min(dp[n], subProb + 1);
        }
      }
    }
    return dp[N];
  }
};

int main()
{
  Solution S;
  vector<int> coins{1, 7, 10};
  int n = coins.size();
  int x = 15;

  int ans = S.minCoinsChange(n, coins, x);
  cout << ans;
}