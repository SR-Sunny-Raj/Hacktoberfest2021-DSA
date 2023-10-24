class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<bool> dp(m + 1, false), dp1(m + 1, false);
        
        dp[0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] != '*')
                break;
            dp[j] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp1[j] = dp[j - 1];
                else if (p[j - 1] == '*')
                    dp1[j] = dp[j] || dp1[j - 1];
                else 
                    dp1[j] = false;
            }
            for (int j = 0; j <= m; j++) {
                dp[j] = dp1[j];
            }
        }
        
        return dp[m];
    }
};