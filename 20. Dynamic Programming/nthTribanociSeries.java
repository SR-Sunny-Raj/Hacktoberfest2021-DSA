class Solution {
    public int tribonacci(int n) {
      
        return solve(n,new int[n+1]);
    }
    static int solve(int n,int dp[]){
       if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(dp[n]!=0){
            return dp[n];
        }
        
        int tri=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
        dp[n]=tri;
        return dp[n];
    }
}
© 2021 GitHub, Inc.
Te
