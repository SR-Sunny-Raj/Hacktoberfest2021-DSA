// author - Nishit Bansal, Nishit278 @github

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int diff = 0;
        for(int i=1;i<prices.size();i++){
            diff= prices[i]-prices[i-1];
            if(diff<0){
                 continue;
            } else {
                max_profit += diff;
            }
        }
        return max_profit;
    }
};