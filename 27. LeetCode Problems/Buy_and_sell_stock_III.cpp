#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int n = prices.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        int minval = prices[0];
        for (int i = 1; i < n; i++) {
            minval = min(minval, prices[i]);
            dp1[i] = max(dp1[i-1], prices[i] - minval);
        }
        int maxval = prices[n-1];
        for (int i = n - 2; i >= 0; i--) {
            maxval = max(maxval, prices[i]);
            dp2[i] = max(dp2[i+1], maxval - prices[i]);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, dp1[i] + dp2[i]);
        }
        return result;
    }
};