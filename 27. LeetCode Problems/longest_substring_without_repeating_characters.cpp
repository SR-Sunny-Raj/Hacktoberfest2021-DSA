//Question:Given a string s, find the length of the longest substring without repeating characters.

  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0, mx=0;int j=0;
        unordered_map<char, int>m;
        
        while(j<s.size())
        {
            if( i<=j && m.count(s[j]) )
            {
                m.erase(s[i]);
                i++;
             
            }
            else 
            {   
                m[s[j]]++;
                mx=max(mx, j-i+1);
                j++;
            }
                
           
            
        }
        return mx;
   
    }
};
