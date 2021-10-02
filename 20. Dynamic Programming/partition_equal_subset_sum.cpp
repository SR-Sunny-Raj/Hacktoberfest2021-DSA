class Solution {
public:
    bool subsetSum(vector<int>&nums, int halfSum){
        //lets create dp table and inititalize it 
        
        //lets create n and w 
        int n=nums.size(), w=halfSum;
        
        //make a dp table and initialize it 
        bool dp[n+1][w+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        
        //now lets write our subset sum code ie. a variation of 0/1 knapsack
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][w];
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum%2!=0){
            //if the sum is odd then can never divide the array into two equal subsets
            return false;
        } 
        
        else {
            //now this is a problem which I have studied previously 
            //if we find a subset whose addition is sum/2 
            //then we just have to call subset sum function which tells us that that subset sun of sum/2
            //exists or not 
            //if it exists then we just have to return ture else false
            //hence lets make a subset sum function
            int halfSum=sum/2;
            return subsetSum(nums, halfSum);
        }
    }
};