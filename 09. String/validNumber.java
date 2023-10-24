/*
Problem Statement: 
A valid number can be split up into these components (in order):
    1. A decimal number or an integer.
    2. (Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):
    1. (Optional) A sign character (either '+' or '-').
    2. One of the following formats:
        a. One or more digits, followed by a dot '.'.
        b. One or more digits, followed by a dot '.', followed by one or more digits.
        c. A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):
    1. (Optional) A sign character (either '+' or '-').
    2. One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
Given a string s, return true if s is a valid number. Otherwise, return false.
    
    Example 1:
    Input: s = "0"
    Output: true
    Explanation: The number can be split into "0".

    Example 2:
    Input: s = " 0.1 "
    Output: true
    Explanation: The number can be split into "0.1".

    Example 3:
    Input: s = "abc"
    Output: false
    Explanation: The number cannot be split into a valid number.

    Example 4:
    Input: s = "1 a"
    Output: false
    Explanation: The number cannot be split into a valid number.

    Example 5:
    Input: s = "2e10"
    Output: true
    Explanation: The number can be split into "2e10".

    Example 6:
    Input: s = " -90e3   "
    Output: true
    Explanation: The number can be split into "-90e3".

    Example 7:
    Input: s = " 1e"
    Output: false
    Explanation: The number cannot be split into a valid number.

    Example 8:
    Input: s = "e3"
    Output: false
    Explanation: The number cannot be split into a valid number.

    Example 9:
    Input: s = " 6e-1"
    Output: true
    Explanation: The number can be split into "6e-1".

    Example 10:
    Input: s = " 99e2.5 "
    Output: false
    Explanation: The number cannot be split into a valid number.

    Example 11:
    Input: s = "53.5e93"
    Output: true
    Explanation: The number can be split into "53.5e93".

    Example 12:
    Input: s = " --6 "
    Output: false
    Explanation: The number cannot be split into a valid number.

    Example 13:
    Input: s = "-+3"
    Output: false
    Explanation: The number cannot be split into a valid number.

    Example 14:
    Input: s = "95a54e53"
    Output: false
    Explanation: The number cannot be split into a valid number.
*/

class validNumber{
    public boolean isNumber(String s) {
        boolean digit=false,e=false,dot=false;
        int countSign=0;
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(Character.isDigit(ch)) digit=true;
            else if(ch=='+' || ch=='-'){
                if(countSign==2) return false;
                if(i>0 && (s.charAt(i-1)!='e' && s.charAt(i-1)!='E')) return false;
                if(i==s.length()-1) return false;
                countSign++;
            }
            else if(ch=='.'){
                if(e || dot) return false;
                if(i==s.length()-1 && !digit) return false;
                dot=true;
            }
            else if(ch=='e' || ch=='E'){
                if(e || !digit || i==s.length()-1) return false;
                e=true;
            }
            else return false;
        }
        return true;
    }
}   