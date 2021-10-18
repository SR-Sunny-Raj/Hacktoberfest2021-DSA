#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
int eve= (n & 0xAAAAAAAA); // get value of even position
int odd=(n & 0x55555555); //odd position
eve=eve>>1; //right shift of even bit
odd=odd<<1; // left shift of odd bit
int out=(eve | odd); //combine both even and or term
return out;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  
