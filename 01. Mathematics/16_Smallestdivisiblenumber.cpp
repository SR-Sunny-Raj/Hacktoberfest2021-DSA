// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    long long getSmallestDivNum(long long n)
    {
        long long ans = 1;
        for(long long i=1;i<=n;i++)
          ans = (ans*i)/(__gcd(ans,i));
        return ans;
        // code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.getSmallestDivNum(n) << endl;
    }
    return 0;
} //
