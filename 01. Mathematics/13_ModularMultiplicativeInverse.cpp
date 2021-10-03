// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	//Complete this function
	int modInverse(int a, int m)
	{
		for (int x = 1; x < m; x++)
        	if (((a%m) * (x%m)) % m == 1)
            	return x;
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
		int a, m;

		//taking input a and m
		cin >> a >> m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m) << endl;
	}
	return 0;
} // } Driver Code Ends
