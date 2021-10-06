/*
    Given a string str of length N, 
    you have to find number of palindromic subsequence      
    (need not necessarily be distinct) which could be formed from the string s.
    Note: You have to return the answer module 109+7;
    
    Input : str = "aab"
    Output : 4
    Explanation :- palindromic subsequence are :"a", "a", "b", "aa" 
    */
    
    
    #include <bits/stdc++.h>
    using namespace std;
    
    long long int  countPS(string s)
    {
        long long int n=s.length(),i,j,l,m=1000000007;
        
        // create a 2D array to store the count of palindromic subsequence
        long long int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(l=1;l<=n;l++)
        {
            for(i=0;l+i<=n;i++)
            {
                j=i+l-1;
                
                // palindromic subsequence of length 1
                if(l==1)
                dp[i][i]=1;
                
                // palindromic subsequence of length 2
                else if(l ==2)
                {
                    if(s[i]==s[j])
                    dp[i][j]=3;
                    else
                    dp[i][j]=2;
                }
                
                // check subsequence of length L is palindrome or not
                else if(s[i]==s[j])
                dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
                else
                dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                
                dp[i][j]+=m;
                dp[i][j]%=m;
            }
        }
        
        // return total palindromic subsequence
        return dp[0][n-1];
       
    }
    
    // Driver code
    int main()
    {
        string s;
        cin>>s;
        cout << "Total palindromic subsequence are : "
            << countPS(s) << endl;
        return 0;
    }