/**Problem Statment
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0.
The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
Hence, there are no valid ways to decode this since all digits need to be mapped.

Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

**/
#include<bits/stdc++.h>
using namespace std;
int numDecodings(string s) {
        int n=s.size();
        if((n==1 && s[0]=='0') || s[0]=='0')
            return 0;
        else if(n==1 && s[0]!='0')
            return 1;
        vector<int> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0' && s[i-1]=='0')
            {
                dp[i]=0;
            }                
            else if(s[i]!='0' && s[i-1]=='0')
            {
                dp[i]=dp[i-1];
            }
            else if(s[i]=='0' && s[i-1]!='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')
                dp[i]=(i!=1?dp[i-2]:1);                
            }
            else
            {
                dp[i]=dp[i-1];               
                if(s[i-1]=='1' || (s[i-1]=='2' && (s[i]>='1' && s[i]<='6')))
                dp[i]+=(i!=1?dp[i-2]:1);
            }            
        }        
        return dp[n-1];
    }
int main()
{
  string s;
  cin>>s;
  cout<<numDecodings(s);
  return 0;
}
