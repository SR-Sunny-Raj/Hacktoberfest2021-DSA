/******************************************************************************

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

https://leetcode.com/problems/minimum-window-substring/

*******************************************************************************/

class Solution {
public:
    string minWindow(string s, string t) {


        unordered_map<char, int> letters;
        for(auto c : t) letters[c]++;
        int count = 0;
        int low = 0, min_length = INT_MAX, min_start = 0;
        for(int high = 0; high<s.length(); high++) {
            if(letters[s[high]] > 0) count++;
            letters[s[high]]--;
            if(count == t.length()) {
                while(low < high && letters[s[low]] < 0) letters[s[low]]++, low++;
                if(min_length > high-low) min_length = high-(min_start=low)+1;
                letters[s[low++]]++;
                count--;
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length);

    }
};
