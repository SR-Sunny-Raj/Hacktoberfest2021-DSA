/*
Problem Statement:Given a binary string S consisting of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.
                  Note: In the case of all 1s, the answer will be -1.
Example 1:
Input : S = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6.

Example 2:
Input: S = "111111"
Output: -1
Explanation: S contains 1s only 
*/

//Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int i,n=S.length();
        int maxi=-1,cnt=0;
        for(i=0;i<n;i++)
        {
            if(S[i]=='1')
                cnt--;
            else
                cnt++;
            maxi=max(maxi,cnt);
            if(cnt<0)
                cnt=0; 
	    }
	    return maxi;
	}
};

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;
   	  Solution ob;
      cout << ob.maxSubstring(s) << "\n";
   	}
    return 0;
}
