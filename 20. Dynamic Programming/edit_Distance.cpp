/*
Task. The goal of this problem is to implement the algorithm for computing the edit distance between two
strings.
Input Format. Each of the two lines of the input contains a string consisting of lower case latin letters.
Constraints. The length of both strings is at least 1 and at most 100.
Output Format. Output the edit distance between the given two strings.
//////////
Sample 1.
Input:
   ab
   ab
Output:
   0

//////////
Sample 2.
Input:
   short
   ports
Output:
   3
*/

#include <bits/stdc++.h>
using namespace std;
int minDis(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{

    // If any string is empty,
    // return the remaining characters of other string

    if (n == 0)
        return m;

    if (m == 0)
        return n;

    // To check if the recursive tree
    // for given n & m has already been executed

    if (dp[n][m] != -1)
        return dp[n][m];

    // If characters are equal, execute
    // recursive function for n-1, m-1

    if (s1[n - 1] == s2[m - 1])
    {
        if (dp[n - 1][m - 1] == -1)
        {
            return dp[n][m] = minDis(s1, s2, n - 1, m - 1, dp);
        }
        else
            return dp[n][m] = dp[n - 1][m - 1];
    }

    // If characters are nt equal, we need to

    // find the minimum cost out of all 3 operations.

    else
    {
        int m1, m2, m3; // temp variables

        if (dp[n - 1][m] != -1)
        {
            m1 = dp[n - 1][m];
        }
        else
        {
            m1 = minDis(s1, s2, n - 1, m, dp);
        }

        if (dp[n][m - 1] != -1)
        {
            m2 = dp[n][m - 1];
        }
        else
        {
            m2 = minDis(s1, s2, n, m - 1, dp);
        }

        if (dp[n - 1][m - 1] != -1)
        {
            m3 = dp[n - 1][m - 1];
        }
        else
        {
            m3 = minDis(s1, s2, n - 1, m - 1, dp);
        }
        return dp[n][m] = 1 + min(m1, min(m2, m3));
    }
}

// Driver program
int main()
{

    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << minDis(str1, str2, n, m, dp);
    return 0;
}
