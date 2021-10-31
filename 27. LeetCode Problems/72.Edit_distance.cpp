// Leetcode 72: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// A Space efficient Dynamic Programming
// based C++ program to find minimum
// number operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;
  
void EditDistDP(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
  
    // Create a DP array to memoize result
    // of previous computations
    int DP[2][len1 + 1];
  
    // To fill the DP array with 0
    memset(DP, 0, sizeof DP);
  
    // Base condition when second string
    // is empty then we remove all characters
    for (int i = 0; i <= len1; i++)
        DP[0][i] = i;
  
    // Start filling the DP
    // This loop run for every
    // character in second string
    for (int i = 1; i <= len2; i++) {
        // This loop compares the char from
        // second string with first string
        // characters
        for (int j = 0; j <= len1; j++) {
            // if first string is empty then
            // we have to perform add character
            // operation to get second string
            if (j == 0)
                DP[i % 2][j] = i;
  
            // if character from both string
            // is same then we do not perform any
            // operation . here i % 2 is for bound
            // the row number.
            else if (str1[j - 1] == str2[i - 1]) {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }
  
            // if character from both string is
            // not same then we take the minimum
            // from three specified operation
            else {
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j],
                                       min(DP[i % 2][j - 1],
                                           DP[(i - 1) % 2][j - 1]));
            }
        }
    }
  
    // after complete fill the DP array
    // if the len2 is even then we end
    // up in the 0th row else we end up
    // in the 1th row so we take len2 % 2
    // to get row
    cout << DP[len2 % 2][len1] << endl;
}
  
// Driver program
int main()
{
    string str1 = "food";
    string str2 = "money";
    EditDistDP(str1, str2);
    return 0;
}