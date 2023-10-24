/*
Problem link: https://leetcode.com/problems/decode-string/

Problem Statement: Given an encoded string, return its decoded string.

I/P: str = "3[a]2[bc]"
O/P: "aaabcbc"

Approach: Maintain 2 stacks: one for storing number and other for storing the word string.
          Traverse the string, if the character is a number or alphabet, store it in separate variables,
                               if the character is '[', push the number and word in the respective stacks,
                               if the character is ']', pop the stack and append it in answer.
          Return the answer.

*/

#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> wordStack;
    
    int number = 0;
    string word = "";
    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];
        if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
        }
        else if (isalpha(ch)) {
            word += ch;
        } 
        else if (s[i] == '[') {
            wordStack.push(word);
            countStack.push(number);
            word = "";
            number = 0;
        } 
        else {     //If s[i] is ']'
            int topMult = countStack.top(); countStack.pop();
            string topS = wordStack.top(); wordStack.pop();
            for (int i = 0; i < topMult; i++) {
                topS.append(word);
            } 
        word = topS;
        } 
    }
    return word;
}

int main() {

    string str = "3[a]2[bc]";
    cout << decodeString(str) << endl; //O/P: "aaabcbc"

    return 0;
}
  