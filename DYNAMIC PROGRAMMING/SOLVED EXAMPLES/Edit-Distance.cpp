//Problem Link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends