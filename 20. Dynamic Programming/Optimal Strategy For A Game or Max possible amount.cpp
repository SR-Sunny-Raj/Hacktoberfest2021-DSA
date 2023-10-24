// ## Question Link : ( Extremely good question to build up your Dynamic Programming logic)
// > Optimal Strategy for a game : https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1# 
// > Max possible amount : https://practice.geeksforgeeks.org/problems/max-possible-amount2717/1 

class Solution
{
    public:
    int maxAmount(int arr[], int n)
    {
        int dp[n][n];
        
        for(int i = 0; i < n - 1; i++)
        {
            dp[i][i + 1] = max(arr[i], arr[i + 1]);
        }
        
        for(int gap = 3; gap < n; gap += 2)
        {
            for(int i = 0; i + gap < n; i++)
            {
                int j = i + gap;
                
                int val1 = arr[i] + min(dp[i + 2][j + 0], dp[i + 1][j - 1]);
                int val2 = arr[j] + min(dp[i + 1][j - 1], dp[i + 0][j - 2]);
                
                dp[i][j] = max(val1, val2);
            }
        }
        
        return dp[0][n - 1];
    }
};

