// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isPrime(int N)
    {
        for(int i=2;i<=sqrt(N);i++)
        {
            if(N%i==0)
             return false;
        }
        return true;
        //Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int T;      //testcases
    cin >> T;   //input testcases
    while (T--) //while testcase have not been exhausted
    {
        int N;
        cin >> N; //input n
        Solution ob;
        if (ob.isPrime(N))
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
