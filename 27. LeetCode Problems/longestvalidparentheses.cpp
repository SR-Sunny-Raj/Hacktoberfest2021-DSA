/*32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".*/
int longestValidParentheses(char * s){
    if(!*s) return 0; 

    for(int i = 0, j = 1; s[j]; j++){  //Step 1: replace valid parentheses with 1. Like "((()()(()" -> "((1111(11"
        while(s[i] == 1 && i > 0) i--;
        while(s[j] == 1) j++;
        
        if(s[i] == '(' && s[j] == ')'){  
            s[i] = 1;
            s[j] = 1;
            if(i != 0) i--;
        }
        else i = j;
    }

    int max = 0;
    for(int i = 0, local = 0; s[i]; i++, local = 0){ //Step 2: count it
         while(s[i] == 1){
             i++;
             local++;
         } 
        if(local > max) max = local;
        if(!s[i]) break;
    }
    return max;
}
