/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		while(a-- >0)
		{

		    int b=sc.nextInt();
		    int c=sc.nextInt();
		    int d=sc.nextInt();
		    int e=sc.nextInt();
		    int count=0;
		    if(b==c)
		    {
		        if(d==e)
		        {
		            count=1;
		        }
		    }
		    else if(b==d)
		    {
		        if(c==e)
		        {
		            count=1;
		        }
		    }
		     else if(b==e)
		    {
		        if(c==d)
		        {
		            count=1;
		        }
		    }
		    if(count==0)
		    {
		        System.out.println("NO");
		        
		    }
		    else
		    System.out.println("YES");
		        
		}
	}
}
