#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStepsToOne(int n)
    {
        int dp[100] = {INT_MAX};
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {

            int op1, op2, op3;
            op1 = op2 = op3 = INT_MAX;

            if (i % 3 == 0)
                op1 = dp[i / 3];

            if (i % 2 == 0)
                op2 = dp[i / 2];

            op3 = dp[i - 1];

            dp[i] = min(min(op1, op2), op3) + 1;
        }
        return dp[n];
    }
};

int main()
{
    Solution S;
    int n = 5;
    cout << S.minStepsToOne(n);
}