/*
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:

Input: s = "ab", goal = "ba"

Output: true

Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:

Input: s = "ab", goal = "ab"

Output: false

Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:

Input: s = "aa", goal = "aa"

Output: true

Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

Example 4:

Input: s = "aaaaaaabc", goal = "aaaaaaacb"

Output: true

Constraints:

1 <= s.length, goal.length <= 2 * 104

s and goal consist of lowercase letters.
*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length())
            return false;
        int i;
          unordered_map<char,int>mp,mp1;
           for(i=0;i<A.length();i++)
                mp[A[i]]++,mp1[B[i]]++;
        if(A==B){
            for(auto it=mp.begin();it!=mp.end();it++){
                if((it->second)>1)
                    return true;
            }
            return false;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second!=mp1[it->first])
                return false;
        }
        int count=0;
        for(i=0;i<A.length();i++){
            if(A[i]!=B[i])
                count++;
        }
        if(count==2)
            return true;
        return false;
   
    }
};
