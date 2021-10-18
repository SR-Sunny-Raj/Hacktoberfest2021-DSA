//Question Statement : https://codeforces.com/contest/1421/problem/C
package palindromifier;
import java.util.Scanner;

public class Palindromifier {

    public static void main(String[] args) {
        
        String s;
        Scanner in=new Scanner(System.in);
        s=in.next();
        int n=s.length();
        StringBuilder sb=new StringBuilder(s);
              if((sb.toString()).equals(sb.reverse().toString())){
                    System.out.println("0");
                }
                else{
                    System.out.println("3");
                    System.out.println("R "+(n-1));
                    System.out.println("L "+n);
                    System.out.println("L 2");
                }
    }  
}
    
