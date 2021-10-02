class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        bool dp[N+1][sum+1];
        memset(dp,false,sizeof(dp));

        for(int i=0; i<N+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0 && j==0){
                    dp[i][j] = true;
                }else if(i==0){
                    dp[i][j] = false;
                }else if(j==0){
                    dp[i][j] = true;
                }else{
                    if(dp[i-1][j] == true){
                        dp[i][j] = true;
                    }else {
                        int val = arr[i-1];
                        if(j >= val){
                            if(dp[i-1][j-val] == true){
                                dp[i][j] = true;
                            }
                        }
                    }
                }
            }
        }
        return dp[N][sum];
    }
};
