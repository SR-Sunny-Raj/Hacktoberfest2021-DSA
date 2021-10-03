package com.company;
import java.util.Scanner;
import java.util.Stack;

public class ReversString {

    public static void main(String[] args) {
	
       String s = "sampath";
       Scanner scanner = new Scanner(System.in);
       System.out.print("Enter your String : ");
       String str = scanner.nextLine();
       ReversString re = new ReversString();
       re.revers(str);
      
    }
}

class ReversString{

    public void revers(String s){

        char ch[] = s.toCharArray();

        Stack<Character> stack = new Stack<>();

        for(int i=0;i<ch.length;i++){
            stack.push(ch[i]);
        }

        for(int i=0;i<ch.length;i++){
            ch[i] = stack.pop();
        }
        for(int i=0;i< ch.length;i++){
            System.out.print(ch[i]);
        }
    }

}

