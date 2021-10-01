

   
/*Evaluate the value of an arithmetic expression in Reverse Polish/Post Fix Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.
 
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 
Constraints:
1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
  
  */







class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int>s;
        for(int i=0;i<t.size();i++){
            if(t[i]=="+" or t[i]=="-" or t[i]=="*" or t[i]=="/"){
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                switch(t[i][0]){
                    case '+':
                        s.push(op1+op2);
                        break;
                    case '-':
                        s.push(op1-op2);
                        break;
                    case '*':
                        s.push(op1*op2);
                        break;
                    case '/':
                        s.push(op1/op2);
                        break;
                }
            }
            else{
                s.push(stoi(t[i]));
            }
        }
        return s.top();
    }
};

