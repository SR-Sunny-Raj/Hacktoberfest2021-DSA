import java.util.*;
class Solution {
	public static int countBracketReversals(String input) {
		//Your code goes here
        int len = input.length();
        if(len%2!=0)
            return -1;
        int open=0,close=0,rev=0;
        for(int i=0;i<len;i++){
            if(input.charAt(i)=='{')
                open++;
            else{
                if(open==0)
                    close++;
                else
                    open--;
            }
        }
        rev = (int)(Math.ceil(open/2.0)+Math.ceil(close/2.0));
        return rev;
	}
}
public class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String expression = s.nextLine();
    	System.out.println(Solution.countBracketReversals(expression));
	}
}