package Stack;

import java.util.ArrayDeque;
import java.util.Scanner;

public class BalancedParentheses {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string of parenthesis");
        String s  = sc.nextLine();
        System.out.println(isBalanced(s));
    }
    public static boolean matched(char a, char b){
        return( (a=='(' && b==')')||
                (a=='{' && b=='}')||
                (a=='[' && b==']') );
    }

    public static boolean isBalanced(String str){
        ArrayDeque<Character> s = new ArrayDeque<>();
        for (int i = 0; i < str.length(); i++) {
            char x = str.charAt(i);

            if(x=='(' || x =='{' || x =='[')
                s.push(x);
            else{
                if(s.isEmpty())
                    return false;
                else if(!matched(s.peek(), x))
                    return false;
                else
                    s.pop();
            }
        }
        return (s.isEmpty());
    }
}
