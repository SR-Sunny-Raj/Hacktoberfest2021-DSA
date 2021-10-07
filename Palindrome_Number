//An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;  
        ss<<x;  
        string s;  
        ss>>s; 
        for(int i=0,j=s.length()-1; i<=j; i++,j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
};
