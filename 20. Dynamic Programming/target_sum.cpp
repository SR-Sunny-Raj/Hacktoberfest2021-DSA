class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = 0;
        
        for(auto x : nums)
            s += x;
             
        //count number of subsets with sum as their summation
       if(s < target || (target + s)&1 )
           return 0;
            
        int n = nums.size();
        int sum = (abs(target) + s)/2;
        int dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                
                else if(i == 0)
                    dp[i][j] = 0;
                
                else if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        
        return dp[n][sum];
    }
};
/*
this problem is similar of just same as the SUBSET SUM PROBLEM
*/