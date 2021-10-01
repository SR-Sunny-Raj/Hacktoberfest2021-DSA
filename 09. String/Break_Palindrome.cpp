/*
Problem Statement:Given a palindromic string of lowercase English letters 
palindrome, replace exactly one character with any lowercase English 
letter so that the resulting string is not a palindrome and that it is 
the lexicographically smallest one possible.
Return the resulting string. If there is no way to replace a character 
to make it not a palindrome, return an empty string.
Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.
Example 2:

Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
Example 3:

Input: palindrome = "aa"
Output: "ab"
Example 4:

Input: palindrome = "aba"
Output: "abb"
 

Constraints:

1 <= palindrome.length <= 1000
palindrome consists of only lowercase English letters.
*/

//Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


string breakPalindrome(string p) {
        if(p.size()==1)return "";
        for(int i=0;i<p.size();i++){
            if(p[i]!='a'){
                if(i==p.size()/2 && p.size()%2==1)continue;
                p[i]='a';return p;
            }
        }
        p[p.size()-1]='b';
        return p;
    }
int main(){
    int t;
    cin>>t;
    while(t-->0){
        string s;
        cin>>s;
        cout<<breakPalindrome(s)<<endl;
    }
    return 0;
}
