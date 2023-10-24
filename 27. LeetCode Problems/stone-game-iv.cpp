class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1);
        //dp[i][0] : 1 if Alice wins with i stones, else 0
        //dp[i][1] : 1 if Bob wins with i stone, else 0
        dp[1] = 1;
       
       
        for(int i=2;i<=n;i++){
            for(int j=1; j*j<=i;j++){
                if(!dp[i-j*j]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n]==1;
    }
};
