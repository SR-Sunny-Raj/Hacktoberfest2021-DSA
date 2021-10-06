/* how it is different from question of swapping bracket is that in that question we have given both opening and closing bracet that means we cannot increse or decrease the number of them but in this question we have 
to change the bracket from opening to closing or closing to opening by our choice no need to swap from any other position for eg {{{{ so we can change last two opening into closing 
but in preious case we can not do that*/

#include <iostream>
#include <string>
using namespace std;
#include<stack>
int countBracketReversals(string input) {
	// Write your code here
      int len = input.length(); 
  
    // length of expression must be even to make 
    // it balanced by using reversals. 
    if (len%2) 
       return -1; 
  
    // After this loop, stack contains unbalanced 
    // part of expression, i.e., expression of the 
    // form "}}..}{{..{" 
    stack<char> s; 
    for (int i=0; i<len; i++) 
    { 
        if (input[i]=='}' && !s.empty()) 
        { 
            if (s.top()=='{') 
                s.pop(); 
            else
                s.push(input[i]); 
        } 
        else
            s.push(input[i]); 
    } 
  
  
    int red_len = s.size(); 
  
    // count opening brackets at the end of 
    // stack 
    int n = 0; 
    while (!s.empty() && s.top() == '{') 
    { 
        s.pop(); 
        n++; 
    } 
  
  
    return (red_len/2 + n%2); 
} 

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
