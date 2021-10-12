/*
## Number of segments in a String ##

Problem Link - https://leetcode.com/problems/number-of-segments-in-a-string/

Problem statement - You are given a string s, return the number of segments in the string. A segment is defined to be a contiguous sequence of non-space characters.

Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Example 2:

Input: s = "Hello"
Output: 1

## Constraints: ##

0 <= s.length <= 300
s consists of lower-case and upper-case English letters, digits or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.
*/

class Solution
{
public:
    int countSegments(string s)
    {
        int count = 0;
        stringstream ss(s);
        while (ss >> s)
        {
            count += 1;
        }
        return count;
    }
};
