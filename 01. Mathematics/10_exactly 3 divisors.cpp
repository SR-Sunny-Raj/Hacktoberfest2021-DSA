// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int exactly3Divisors(int n)
    {
     cout << "Numbers with 3 divisors : "<< endl;
    for(int i = 2; i * i <= n; i++)
    {        
        // Checks for prime
        if (isPrime(i)) //if prime checks if its square is less than or equal to n
            if (i * i <= n)
            {                
                // Print numbers 
                cout << i * i << " ";
            }
        }
    }
    return 0;
    }
    //method for checking whether number is prime or not
    bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;        
    for(int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
};

// { Driver Code Starts.

int main()
{
    int T;

    //taking testcases
    cin >> T;
    while (T--)
    {
        int N;

        //taking N
        cin >> N;
        Solution ob;
        //calling function exactly3Divisors()
        cout << ob.exactly3Divisors(N) << endl;
    }
    return 0;
} // } Driver Code Ends
