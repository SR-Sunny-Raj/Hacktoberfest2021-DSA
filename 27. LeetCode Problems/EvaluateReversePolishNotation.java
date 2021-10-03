package testing;


/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

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
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].*/
public class EvaluateReversePolishNotation {

    public int evalRPN(String[] tokens) {
        Stack<String>stack=new Stack<String>();
        int sum=0;
        for(int i=0;i<tokens.length;i++){
            if(tokens[i].equals("+") || tokens[i].equals("-") || tokens[i].equals("*")|| tokens[i].equals("/")){
                String t1=stack.pop();
                int tt1,tt2;
                if(t1.charAt(0)=='-'){
                 String temp=t1.substring(1,t1.length());
                    tt1=Integer.parseInt(temp);
                    tt1=-tt1;
                }else{
                    tt1=Integer.parseInt(t1);
                }
                String t2=stack.pop();
                if(t2.charAt(0)=='-'){
                    String temp=t2.substring(1,t2.length());
                    tt2=Integer.parseInt(temp);
                    tt2=-tt2;
                }else{
                    tt2=Integer.parseInt(t2);
                }
                if(tokens[i].equals("+")){
                  sum=tt2+tt1;  
                    String tempo=Integer.toString(sum);
                    stack.add(tempo);
                }
                else if(tokens[i].equals("-")){
                  sum=tt2-tt1;  
                    String tempo=Integer.toString(sum);
                    stack.add(tempo);
                }
                else if(tokens[i].equals("*")){
                  sum=tt2*tt1;  
                    String tempo=Integer.toString(sum);
                    stack.add(tempo);
                }
                else{
                    sum=tt2/tt1;
                        String tempo=Integer.toString(sum);
                    stack.add(tempo);
                }
            }
            else{
                stack.add(tokens[i]);
            }
        }
        return Integer.parseInt(stack.pop());
    }
}