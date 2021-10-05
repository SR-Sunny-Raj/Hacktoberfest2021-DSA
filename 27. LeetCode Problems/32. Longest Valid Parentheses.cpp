#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        stk.push(-1);
        int large=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                stk.push(i);
            if(s[i]==')')
            {
                if(!stk.empty())
                    stk.pop();
                if(!stk.empty())
                {
                    large=max(large,i-stk.top());
                   // stk.pop();
                }
                else
                    stk.push(i);
            }
        }
        return large;
    }
};
