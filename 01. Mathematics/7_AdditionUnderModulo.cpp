// { Driver Code Starts
//Initial Template for C++

// #include <bits/stdc++.h>
#include <iostream>
// #include <>
using namespace std;
#define FIRST_10_DIGIT_PRIME 1000000007 //(10^9)+7
// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	long long sumUnderModulo(long long a, long long b)
	{
		return ( (a%FIRST_10_DIGIT_PRIME) + (b%FIRST_10_DIGIT_PRIME)) % FIRST_10_DIGIT_PRIME;
	}
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long a;
		long long b;
		cin >> a >> b;
		Solution ob;
		cout << ob.sumUnderModulo(a, b) << endl;
	}
	return 0;
} // } Driver Code Ends
