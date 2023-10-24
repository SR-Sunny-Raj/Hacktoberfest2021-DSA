/*

Problem Link - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

Problem Statement - Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

* It is the empty string, contains only lowercase characters, or
* It can be written as AB (A concatenated with B), where A and B are valid strings, or
* It can be written as (A), where A is a valid string.

Example 1
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2
Input: s = "a)b(c)d"
Output: "ab(c)d"
*/    
    
    
    #include <bits/stdc++.h>
    using namespace std;
 
    string minRemoveToMakeValid(string s) 
    {
        // stack to store the index and type of parentheses
        stack<pair<char,int>> st;
        int i,j=0;
        string r="";
        
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push({'(',i});
            
            else if(s[i]==')')
            {
                if(!st.empty() && st.top().first=='(')
                    st.pop();
                else
                    st.push({')',i});
            }            
        }
        
        // erasing the invalid parentheses
        while(!st.empty())
        {
             s.erase(s.begin() + st.top().second);
             st.pop();
        }
        
        return s;
    }
 
    // Driver Code
    int main()
    {
        string s;
        cin>>s;
        
        cout<<minRemoveToMakeValid(s)<<"\n";
    }
