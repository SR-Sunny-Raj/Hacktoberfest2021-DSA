#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int price[], int i, int j, int year)
    {

        if (i > j)
        {
            return 0;
        }

        int p1 = price[i] * year + maxProfit(price, i + 1, j, year + 1);
        int p2 = price[j] * year + maxProfit(price, i, j - 1, year + 1);

        int ans = max(p1, p2);
        return ans;
    }
};

int main()
{
    Solution S;

    int price[] = {2, 3, 5, 1, 4};
    int n = sizeof(price) / sizeof(price[0]);
    int year = 1;
    int i = 0, j = n - 1;

    cout << S.maxProfit(price, i, j, year);
}