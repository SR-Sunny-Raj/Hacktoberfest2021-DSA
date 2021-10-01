// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Complete this function
    double termOfGP(int A, int B, int N)
    {
        //first finding ratio
        double ratio = double(B)/double(A);
        //Nth term according to the formula
        double ans = A*(pow(ratio,N-1));
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int T;    //testcases total
    cin >> T; //input the testcases

    for (int i = 0; i < T; i++) //white testcases are not exhausted
    {
        int A, B;
        cin >> A >> B; //input first and second term of gp
        int N;
        cin >> N; //input n
        Solution ob;
        cout << floor(ob.termOfGP(A, B, N)) << endl;
    }

    return 0;
}

// } Driver Code Ends
