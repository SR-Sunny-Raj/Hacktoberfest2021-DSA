#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        stack<int>st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                
                maxi=max(maxi,i-st.top());
                
            }
        }
        return maxi;
    }
};
int main()
{
   int t;
  cin>>t;
  while(t--)
  {
      string S;
      cin>>S;
    Solution ob;
    cout<<ob.findMaxLen(S)<<endl;
  }
  return 0;
}
