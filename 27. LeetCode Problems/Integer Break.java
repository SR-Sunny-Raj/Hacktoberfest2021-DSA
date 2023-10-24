//Integer Break is a problem on Leetcode in the Dynamic Programming ThreadGroup
//Problem URL: https://leetcode.com/problems/integer-break/
//It is a very good problem and my solution here is faster than 100% submissions

class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int i,j;
        int dp[n+1][n+1];
        for(i=0;i<=n;i++)
        {
            dp[i][0]=0;dp[0][i]=1;
            // dp[i][1]=1;dp[1][i]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j>i)
                    dp[i][j]=dp[i][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-j][j]*j);
            }
        }
        return dp[n][n];
    }
};