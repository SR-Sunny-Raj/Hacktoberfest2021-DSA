/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/
class Solution {
public:
    string reverseWords(string s) {
    int start=0;
    int end=0;
    string str;
    for(int i=0;i<=s.size();i++){
       
        if(i == s.size() || s[i] == ' '){
            end=i;
            cout<<end;
            reverse(s.begin()+start,s.begin()+end);
            start=end+1;
        }
        
    }
           return s;
    }
};