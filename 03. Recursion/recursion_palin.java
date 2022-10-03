import java.io.*;
import java.util.*;
                  
                   
public class  recursion_palin {
         
    public static boolean f(String s,int l,int r)
    {if(l>=r)
        {
return true;
        }

        if(s.charAt(l)!=s.charAt(r))
        return false;

        return f(s,l+1,r-1);
    }

     public static void main(String args[]) throws IOException {
                   
         Scanner sc = new Scanner(System.in);
        String s=sc.next();
        int r=s.length()-1;
        System.out.println(f(s,0,r)); 
         sc.close();
     }
 }