// We have two strings, we need to find the number of distinct subsequences of string 1 which equals string 2.

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// As a typical way to implement a dynamic programming algorithm, we construct a matrix dp,
// where each cell dp[i][j] represents the number of solutions of aligning substring T[0..i] with S[0..j];

class Solution {
public:
    int numDistinct(string s, string t) {
        ull l1 = s.length(), l2 = t.length();
        vector<vector<ull>> dp(l1+1 , vector<ull> (l2+1, 0));
        for(int i=0; i<l1; i++) dp[i][0] = 1;
        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                dp[i][j] = (s[i-1] == t[j-1] ? dp[i-1][j] + dp[i-1][j-1] : dp[i-1][j]);
            }
        }
        return dp[l1][l2];
    }
};