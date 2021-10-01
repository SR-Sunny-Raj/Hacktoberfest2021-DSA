//Basic Eulidean Algorithm to find GCD
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int gcd(int a,int b)
    {   
        if (a == 0)
        return b;
        
        return gcd(b % a, a);
    }
};

// { Driver Code Starts.

int main()
{
    int T;    // number of testcases
    cin >> T; // input number of testcases
    while (T--)
    {
        int a,b;
        cin >> a>>b;
        Solution ea;
        cout << ea.gcd(a,b) << endl; // print the output
    }
    return 0;
} // } Driver Code Ends
