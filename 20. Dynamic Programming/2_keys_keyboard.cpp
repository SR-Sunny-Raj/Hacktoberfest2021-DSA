class Solution {
public:
    int solve(int n){
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            dp[i]=i; //prime number
            for(int j=i-1;j>=2;j--){
                if(i%j==0){
                    dp[i] = dp[j] + (i/j);
                    break;
                }
            }
        }
        return dp[n];
    }
    int minSteps(int n) {
        //for any value n we need at max n operations 
        //this can be found using observations
        //eg f(15) need f(5) + (15/5) operations
        //here we can see that we need greatest factor lesser than 15 added to the time 15 come from 5
        
        //f(n) = f(x) + (n/x)
        //where x is the largest factor of n 
        
        return solve(n);
    }
};