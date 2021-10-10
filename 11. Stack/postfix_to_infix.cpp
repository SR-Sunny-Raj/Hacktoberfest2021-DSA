/*
This code is for Postfix to Infix convertion
Algo->
Iterate through the string from left to right
    Check if character is operand or not
    if character is operand
        push it on the stack
    if character is operator
        pop operand1 from the stack
        pop operand2 from the stack
        perform (operand2 operator operand1)
        push back the result onto the stack
After completing the iteration, pop out the string from stack and return it          


*/



#include<bits/stdc++.h>
using namespace std;

int isOperand(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;    
}

string toInfix(string str){
    stack<string> stack;

    for(int i=0; str[i] != '\0';i++){

        if(isOperand(str[i]) == 1){
            string x(1, str[i]);
            stack.push(x);
        }
        else if(isOperand(str[i]) == 0){
            string operand1 = stack.top();
            stack.pop();
            string operand2 = stack.top();
            stack.pop();

            stack.push("(" + operand2 + str[i] + operand1 + ")");
        }
    }

    return stack.top();
}

int main(){
    string str = "ABC/-DE/*";
    cout << "The Infix String of " << str << " is " << toInfix(str) << endl;
    return 0;
}