## Question Link : https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1# <br>

### Video Solution : https://www.youtube.com/watch?v=jdfpGSSyN2I&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=3 <br>


### SOLUTION : ( ACCEPTED ) 

> sumit sir's solution 

```
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
```

SOLUTION : ( USING FUNCTION Debojyoti Sinha's) 
```
class Solution
{
    void findLIS(vector<int> arr, int LIS[], int n)
    {
        LIS[0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            LIS[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(arr[j] < arr[i])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }
    }
    
    void findLDS(vector<int> arr, int LDS[], int n)
    {
        LDS[n - 1] = 1;
        
        for(int i = n - 2; i >= 0; i--)
        {
            LDS[i] = 1;
            for(int j = n - 1; j > i; j--)
            {
                if(arr[j] < arr[i])
                {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }
    }
    
    public:
    int LongestBitonicSequence(vector<int> arr)
    {
        int n = arr.size();
        
        int LIS[n];
        findLIS(arr, LIS, n);
        
        int LDS[n];
        findLDS(arr, LDS, n);
        
        int res = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            res = max(res, LIS[i] + LDS[i] - 1);
        }
        
        return res;
    }
};
```

SOLUTION : MINE ( FREAKING PROUD ) 
> I got this idea from an comment section that reversing the array and feeding it to out LIS function can give us the reverse array od DCS (decreasing continous subsequence) and then by reversing it one more time we can get both arrays of LIS and DCS, then we can just compare the same element in both array and check for the largest - 1 ;
```
class Solution
	{
	public:
	
	int* LIS(vector<int> arr, int n)
    {
        int* dp = new int[n];
        int vmax = 0;
	    for(int i=0;i<n;i++)
        {
	        int max =0;
	        for(int j=0;j<i;j++)
            {
	            if(arr[j]<arr[i])
                {
	                if(dp[j]>max)
                    {
	                    max = dp[j];
	                }
	            }
	        }
	        
	        dp[i] = max +1;

            if(dp[i]>vmax){
                vmax = dp[i];
            }
        }
    
        return dp;
    }

	int LongestBitonicSequence(vector<int>arr)
	{   int n = arr.size();
	    int* inc = LIS(arr,n);
        reverse(arr.begin(), arr.end());
        int* dec = LIS(arr,n);
        reverse(dec, dec + n);
        int omax = 0;
        for(int i=0;i<n;i++){
            if(inc[i]+dec[i]>omax){
                omax = inc[i]+dec[i] -1;
            }
        }
        return omax;
    }
};
```
