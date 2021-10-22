// Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Solution by Sameer Aggrawal (Github id- sameer-19)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a[100002]={0},mx=0,i;
        for(i=prices.size()-1;i>=0;i--)
        {
            mx=max(mx,prices[i]);
            a[i]=mx;
        }
        int ans=0;
        for(i=0;i<prices.size();i++)
        {
            if(a[i]>prices[i]) ans=max(ans,a[i]-prices[i]);
        }
        return ans;
    }
};
