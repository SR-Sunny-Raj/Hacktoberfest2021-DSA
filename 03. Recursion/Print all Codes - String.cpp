/*
Print all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <iostream>
#include <string.h>
using namespace std;

void print(string input, string output)
{
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    int n = input[0] - '0';
    char ch = (char)n +'a' -1;
    if(n==0){
        ch = '\0';
    }
   	print(input.substr(1),(output+ch));
    
    n = stoi(input.substr(0,2));
    if(n>=10 && n<=26)
    {
        
        ch = (char)n +'a' -1;
   		print(input.substr(2),(output + ch)); 
        
    }
}


void printAllPossibleCodes(string input) {
    string output = "";
    print (input,output);
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
