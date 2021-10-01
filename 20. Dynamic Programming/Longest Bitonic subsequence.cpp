// Question Link : https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1# 


	class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    int n = arr.size();
	    int dp[n]={0};
	    
	    for(int i=0;i<n;i++){
	        int max =0;
	        
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                if(dp[j]>max){
	                    max = dp[j];
	                }
	            }
	        }
	        
	        dp[i] = max +1;
	    }
	    
	    
	   int lds[n]={0};
	   for(int i=n-1;i>=0;i--){
	        int max =0;
	        
	        for(int j=n-1;j>i;j--){
	            if(arr[j]<arr[i]){
	                if(lds[j]>max){
	                    max = lds[j];
	                }
	            }
	        }
	        lds[i] = max +1;
    }
	    
	    int omax=0;
	    for(int i=0;i<n;i++){
	        if((dp[i]+lds[i])-1>omax){
	            omax = (dp[i]+lds[i])-1;
	        }
	    }
	
	    return omax;
	}
};
	     
