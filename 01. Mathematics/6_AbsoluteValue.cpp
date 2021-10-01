// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define CHARBIT 8

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int absolute(int I)
    {
        // Your code goes here
        int const mask = I >> (sizeof(int) * CHARBIT - 1);
        return ((I + mask) ^ mask);
    }
};

// { Driver Code Starts.

int main()
{
    int T;    // number of testcases
    cin >> T; // input number of testcases
    while (T--)
    {
        int I;
        cin >> I;
        Solution ob;
        cout << ob.absolute(I) << endl; // print the output
    }
    return 0;
} // } Driver Code Ends
