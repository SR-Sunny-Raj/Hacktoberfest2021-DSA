// Problem link: https://leetcode.com/problems/edit-distance
// Difficulty: Hard  

class Solution {
public:
    unordered_map<string, int>m;
    int go(string s1, string s2, int i, int j){
        if(i == 0)
            return j;
        if(j == 0)
            return i;
        string temp = to_string(i)+"|"+to_string(j);
        if(m.count(temp))
            return m[temp];
        if(s1[i-1] == s2[j-1]){
            m[temp] = go(s1,s2,i-1,j-1);
        }
        else{
            m[temp] = 1+min(go(s1,s2,i-1,j-1),min(go(s1,s2,i,j-1),go(s1,s2,i-1,j)));
        }
        return m[temp];
    }
    int minDistance(string word1, string word2) {
        return go(word1, word2, word1.length(),word2.length());
    }
};