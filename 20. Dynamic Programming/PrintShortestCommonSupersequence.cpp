//Print Shortest Common Supersequence

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find shortest common supersequence string of two strings.
    string shortestCommonSupersequence(string x, string y, int m, int n)
    {
        int dp[m+1][n+1];

        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if(x[i-1] == y[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int i = m, j = n;
        string ans = "";

        while(i > 0 && j > 0)
        {
            if(x[i-1] == y[j-1])
            {
                ans.push_back(x[i-1]);
                i--; 
                j--;
            }
            else if(dp[i][j-1] > dp[i-1][j])
            {
                ans.push_back(y[j-1]);
                j--;
            }
            else
            {
                ans.push_back(x[i-1]);
                i--;
            }
        }

        while(i>0)
        {
            ans.push_back(x[i-1]);
            i--;
        }

        while(j>0)
        {
            ans.push_back(y[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}