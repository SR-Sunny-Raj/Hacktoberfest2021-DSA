// { Driver Code Starts
/*package whatever //do not write package name here */

import java.util.*;

class reverseStringStackGFG {
	public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            Solution obj = new Solution();
            System.out.println(obj.reverse(sc.next()));
        }
	}
}
// } Driver Code Ends


class Solution {
    public void push(Stack<Character> stack, char item)
    {
        stack.push(item);
    }
    public char pop(Stack<Character> stack)
    {
        return stack.pop();
    }
    public String reverse(String S){
        //code here
        Stack<Character> stack = new Stack<Character>();
        String revStr = new String();
        for(int i=0; i<S.length(); i++)
            push(stack, S.charAt(i));
        for(int i=0; i<S.length(); i++)
            revStr = revStr+pop(stack);

        return revStr;
    }

}
