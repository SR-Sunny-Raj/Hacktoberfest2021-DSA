#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPrice(int len[], int price[], int n)
    {
        int dp[100] = {0};
        dp[0] = 0, dp[1] = price[0];

        for (int i = 1; i <= n; i++)
        {

            int ans = INT_MIN;
            for (int j = 0; j < i; j++)
            {
                int cut = len[j];
                int current_ans = price[j] + dp[i - cut];
                ans = max(ans, current_ans);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

int main()
{
    Solution S;
    int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(len) / sizeof(int);

    cout << S.maxPrice(len, price, n);
}