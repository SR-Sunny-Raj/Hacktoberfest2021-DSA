/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/

//solution

class Solution {
    public boolean isAnagram(String s, String t) {

        if (s.length() != t.length())
            return false;

        int arr[] = new int[27];
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            char c = t.charAt(i);
            arr[ch - 'a']++;
            arr[c - 'a']--;
        }

        for (int i = 0; i < 27; i++) {
            if (arr[i] != 0)
                return false;
        }

        return true;

    }
}

// Time complexity: O(N)
// Space complexity: O(1)