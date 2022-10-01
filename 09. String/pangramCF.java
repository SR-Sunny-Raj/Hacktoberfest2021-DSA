import java.util.*;
public class pangramCF {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        int count = 0;
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(s.toLowerCase().contains(String.valueOf(ch)))
            count++;
        }
        if(count == 26)
        System.out.print("YES");
        else
        System.out.print("NO");
        in.close();
    }       
}
