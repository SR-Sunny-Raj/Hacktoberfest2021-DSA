import java.io.*;
import java.util.Scanner;

public class codeforcesdiv31
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++)
        {
            String s=in.next();
            int len=s.length();
            int cnta=0;
            int cntb=0;
            int cntc=0;
            for(int j=0;j<len;j++)
            {
                char ch=s.charAt(j);
                if(ch=='A')
                    cnta++;
                else if(ch=='B')
                    cntb++;
                else if(ch=='C')
                    cntc++;
            }

            if(cntc <= cntb)
            {
                if(cntb-cntc == cnta)
                    System.out.println("Yes");
                else
                    System.out.println("No");
            }
            else
            {
                System.out.println("No");
            }
        }

    }
}
