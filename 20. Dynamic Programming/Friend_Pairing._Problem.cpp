//Implementing Friend-Pairing problem using dynamic programming
//hacktoberfest2021

// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    //Function to return the total number of ways in which 'n' friends can remain single or can be paired up.
    int countFriendsPairings(int n) 
    { 
        // Your code here
        long long int mod=1000000000+7;
        long long int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
            {
                dp[i]=i%mod;
            }
            else
            {
                dp[i]=(dp[i-1]%mod+(i-1)*(dp[i-2]%mod))%mod;
            }
        }
        
        return dp[n]%(mod);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        // reading total friends
    	int n;
    	cin>>n;
    	Solution ob;
        //calling method countFriendsPairings
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends