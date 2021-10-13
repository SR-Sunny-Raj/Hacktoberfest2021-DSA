/** You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

**/
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int n=prices.size()+1,profit=0;
        prices.push_back(-1);
        vector<int> dp(n);
        dp[0]=prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i-1]<prices[i])
                dp[i]=dp[i-1];
            else
            {
                profit+=prices[i-1]-dp[i-1];
                dp[i]=prices[i];
                
            }            
        }        
        return profit;
}
int main()
{
    int n;
    cin>>n;  
    vector<int> prices(n);
    for(int i=0;i<n;i++)
      cin>>prices[i];
    cout<<maxProfit(prices);
    return 0;
}
