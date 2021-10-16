/************** FACTORIAL PROGRAM **************

Theory : Factorial of n is the product of all positive integers less than n and upto 1. 

Problem Statement : Find a Factorial of a given number.

Approach : 
    I)  Get integer value as a input and assign it's value to variable num.
    II) Declare variable fact.
   III) from 1 to value num , multiply each digit and store value in fact.
   IV)  Print fact.

Example :
Input -> 4
Output -> 4! = 24

*/
#include <iostream>
using namespace std;

int main()
{
    long num,fact=1;
    cout<<"Enter a number :";
    cin>>num;
    
    for (int i=1; i<=num ; i++)
    {
        fact = fact * i;
    }
    cout<<num<<"! = "<<fact<<endl;
    return 0;
}

