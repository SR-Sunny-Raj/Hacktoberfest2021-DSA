// Given an integer n, return the least number of perfect square numbers that sum to n.

//     A perfect square is an integer that is the square of an integer;
// in other words, it is the product of some integer with itself.For example, 1, 4, 9, and16 are perfect squares while 3 and 11 are not .

// Input : n = 12 Output : 3 Explanation : 12 = 4 + 4 + 4.

//Solution(Recursive + Memoized Approach):

class Solution
{
public:
  int dp[101][10001];
  int knapsack(int W, int n)
  {
    if (W == 0 || n == 0)
      return INT_MAX;
    if (dp[n][W] != -1)
      return dp[n][W];
    int ps = n * n;
    if (ps <= W)
    {
      int temp = knapsack(W - ps, n);
      return dp[n][W] = min(1 + (temp == INT_MAX ? 0 : temp), knapsack(W, n - 1));
    }
    else
      return dp[n][W] = knapsack(W, n - 1);
  }
  int numSquares(int n)
  {
    memset(dp, -1, sizeof(dp));
    return knapsack(n, (int)sqrt(n));
  }
};