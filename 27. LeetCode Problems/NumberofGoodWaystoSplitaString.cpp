// Problem Link : https://leetcode.com/problems/number-of-good-ways-to-split-a-string/


class Solution {
public:
    int numSplits(string s) 
    {
        int n = s.size();
        unordered_set<int> ls;
        unordered_set<int> rs;
        vector<int> lv(n), rv(n);
        for(int i=0; i<n; i++)
        {
            ls.insert(s[i]);
            rs.insert(s[n-1-i]);
            lv[i] = ls.size();
            rv[n-1-i] = rs.size();
        }
        
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            if(lv[i] == rv[i+1])
                ans++;
        }
        
        return ans;
    }
};
