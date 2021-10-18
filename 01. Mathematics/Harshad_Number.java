/* Aim: To check whether the entered number is a Harshad number or not
 * 
 * A number is said to be harshad number if the entered number is divisible by its sum of the digits. 
 * 
 * Input:an integral number no
 * output:is a Harshad Number or not a Harshad Number
 * 
 * For ex:
 * Input:378
 * Output:378 is a Harshad Number
 * 
 * Intput:987
 * Output:987 is not a Harshad Number
 * 
 * ALGORITHM:
 * STEP 1:START
 * STEP 2:Take an integral number (no) as an input from the user
 * STEP 3:Intialisation of variables used, that are no,n,sum,rem(all of integer type)
 * STEP 4:Use of while loop which continues to execute till the value of number no is > 0
 * STEP 5:rem=no%10
 * STEP 6:sum=sum+rem
 * STEP 7:no=no/10
 * STEP 8:Use if control structure with condition as [n(entered number)%sum ==0]
 * STEP 9:if(n%sum==0) then PRINT "Yes" else PRINT "No"
 * STEP 10:END
 */
 
package Hacktoberfest_SR_Sunny_Raj_Solutions;

import java.util.Scanner; //importing scanner class from util package

public class Harshad_Number {
//start of class
	public static void main(String[] args) 
	{//start of main function
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a number:");
		//take a number no as an input from the user
		int no=sc.nextInt();
		//store the value of no to another variable n
		int n=no;
		//intialize variables sum as 0 and rem
		int sum=0,rem;
		
		//use of while loop
		while(no>0)
		{
			//store the remainder of the number no obtained after dividing with 10 in variable rem 
			rem=no%10;
			//store the sum of the digits of number no 
			sum=sum+rem;
			//
			no=no/10;
        }
		//use of if else control structure
		if(n%sum==0)
		{
			//printing statement for desired output
			System.out.println(n+" is a Harshad Number");
		}
		else
		{
			//printing statement for desired output
			System.out.println(n+" is not a Harshad Number");
		}

	}//end of main function

}//end of class
//**************************************************************************************************************
//OUTPUT:
//Test 1:
//Enter a number:
//8769
//8769 is not a Harshad Number

//Test 2:
//Enter a number:
//6408
//6408 is a Harshad Number
//***************************************************************************************************************
