/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Input: s = "()[]{}"
Output: true

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/


class Solution {
public:
    bool isValid(string s2) {
        stack<char> s1;
        
        for(int i = 0; i < s2.size(); i++) {
            if(s1.empty()) {
                s1.push(s[i]);
            } else {
                if(s1.top() == '(' && s2[i] == ')' || s1.top() == '{' && s2[i] == '}' || s1.top() == '[' && s2[i] == ']') {
                s1.pop();
            } else {
                s1.push(s[i]);
            }
            }
        }
        
        if(s1.empty()) {
            return true;
        }
        return false;
    }
};
