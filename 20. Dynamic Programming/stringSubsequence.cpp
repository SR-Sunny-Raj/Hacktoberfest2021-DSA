// solution of stringsubsequence from mohd sahil

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countWays(string S1, string S2)
    {
        int n = S1.size();
        int m = S2.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i < m + 1; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
} int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.countWays(s1, s2) << endl;
    }
    return 0;
}