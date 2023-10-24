#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int sum) 
	{ 
	    // Your code goes here
	    int dp[n+1][sum+1];
	    for(int i=0;i<n+1;i++)dp[i][0]=0;
	    for(int i=1;i<sum+1;i++)
	    {
	        dp[0][i]=INT_MAX-1;
	        if(i%coins[0]==0) dp[1][i]=i%coins[0];//filling second row
	        else dp[1][i]=INT_MAX-1;
	    }
	    
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=0;j<sum+1;j++)
	        {
	            if(coins[i-1]<=j)
	            dp[i][j]= min(dp[i-1][j],(dp[i][j-coins[i-1]])+1);
	            else
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	    return dp[n][sum]==INT_MAX-1?-1:dp[n][sum];
	    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends