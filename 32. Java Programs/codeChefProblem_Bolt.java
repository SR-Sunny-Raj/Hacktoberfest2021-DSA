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
		Scanner sc=new Scanner (System.in);
		int t=sc.nextInt();
		while(t-- >0)
		{
		    double a=sc.nextDouble();
		    double b=sc.nextDouble();
		    double c=sc.nextDouble();
		    double d=sc.nextDouble();
		    double ans=100/(a*b*c*d);
		    double ret=(double) Math.round(ans*100)/100;
		    if(ret>=9.58)
		    {
		        System.out.println("NO");
		    }
		    else
		    {
		        System.out.println("YES");
		    }
		}
	}
}
