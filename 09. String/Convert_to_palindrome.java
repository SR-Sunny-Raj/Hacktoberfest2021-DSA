import java.io.*;
import java.util.*;
import java.lang.*;
public class Convert_to_palindrome{

    public static boolean checkpalin(String x){
        int lower = 0;
        int higher = x.length() - 1;
        while(higher > lower){
            if(x.charAt(lower++) != x.charAt(higher--))
            return false;
        }
        return true;
    }
    public static void ConvertToPalindrome(String a){
        int len  = a.length();
        int arr[]= new int[len];
        String res="";
        int count = 0;
        for(int i = 1; i < len-1; i++){ 
            char prev = a.charAt(i-1);
            char curr = a.charAt(i+1);
            if(prev == curr){
                arr[count] = i-1; 
                count ++;
            }
        }
        StringBuilder result  = new StringBuilder();
        if(count==0)
            res = a.substring(0,len-1);

        else if(count!=0 && arr[count-1] + 2 == (len -1))
            res = a.substring(0,arr[count-1]);
            
        else if(arr[count-1] + 1 != (len -1)){
            if (a.charAt(len-1) == a.charAt(len-2))
            res = a.substring(0,a.length()-2);
            else res = a.substring(0,a.length()-1);
        }
        result.append(res);
        System.out.println(result.reverse());
    }
    public static void main(String[] args)throws IOException{
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a String: ");
        String str = br.readLine();
        boolean x = checkpalin(str);
        if(x==true) System.out.println("NULL");
        else ConvertToPalindrome(str);
    }
}