//Problem Link:
//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    
    int fibonacci(int n, int m){
        
        m = 2;
        if(n<=1)
            return n;
        
        int res[n];
        res[0] = res [1] = 1;
        
        for(int i=2; i<n; i++){
            res[i]=0;
            for(int j=1; j<=m && j<=i; j++){
                res[i] += res[i-j];
            }
        }
        return res[n-1];
    }
    
    int climbStairs(int n) {
        int m=2;
        return fibonacci(n+1, m);
    }
};
