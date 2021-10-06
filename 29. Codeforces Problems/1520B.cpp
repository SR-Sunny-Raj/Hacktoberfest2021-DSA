/*Codeforces problem link : https://codeforces.com/problemset/problem/1520/B */

/*This Problem is one of the basic brute force counting based problem. The problem describes 
the term "ordinary numbers" . According to the problem an ordinary number is :

-> A positive integer n
-> It's decimal notation has all the digits equal
-> Examples 1,2,11,99 are all ordinary number

We need to determine the number of ordinary numbers less than the number

A very simple approach to the problem can be checking each number less than the integer
and counting the ordinary numbers, but that would be very resource intensive and will result
in TLE.
Another approach is if we create a function that generates the ordinary numbers and run
it till we exceed the number in question.
Let's take an example say we have a number 222, which by observation is an ordinary number
Breaking 2*2 based on weights of its digits i.e units tens etc.
222 = 1*2 + 10*2 + 100*2 => 222 = 2*(1+10+100)
weight of-
units place : 10^0
tens place : 10^1
hundreds place : 10^2 and so on;
Here we observe a pattern that any ordinary number in the form (nnnnnn..) having say m digits
can be written as n(10^0+10^1+10^2+........10^m)
for every (n,m) pair this relation gives a unique number. We can brute force every possible (n,m) pair
till n(10^0+10^1+10^2+........10^m) exceeds the given number. 
contributed by Sameer Trivedi */

#include <iostream>
using namespace std;
int main()
{
    long long int n {},count {},t {};
    cin>> t; // input the number of test cases
    while(t--)
    {
        long long int n;
        cin >> n;
        for (long long int i = 1; i <= n; i =i * 10 + 1) // outer loop for generating weight (m) part
        {
            for (int j = 1; j <= 9;  j++) // inner loop for varying n from 1 to 9
            {
                if (i * j <= n)
                    {
                        count++;
                    }
            }
        }
  cout << count << endl;
  count = 0; // resetting count for next case
    }
return 0;    
}
