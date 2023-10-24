/**
1. Plus One 
Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). The digits are stored such that the most significant digit is first element of array.
 

Example 1:

Input: 
N = 3
arr[] = {1, 2, 4}
Output: 
1 2 5
Explanation:
124+1 = 125, and so the Output
Example 2:

Input: 
N = 3
arr[] = {9,9,9}
Output: 
1 0 0 0
Explanation:
999+1 = 1000, and so the output

Your Task:
You don't need to read input or print anything. You only need to complete the function increment() that takes an integer N, and an array arr of size N as input and returns a list of integers denoting the new number which we get after adding one to the number denoted by the array arr.


Expected Time Complexity:  O(N)
Expected Auxilliary Space: O(1)
 

Constraints:
1 <= N <= 105
0 <= arri <= 9


**/
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
		 // Add 1 to last digit and find carry
		arr[n-1]+=1;
		int carry=arr[n-1]/10;
		arr[n-1]=arr[n-1]%10;
		 // Traverse from second last digit
		for(int i=n-2;i>=0;i--){
			if(carry==1){
				arr[i]+=1;
				carry=arr[i]/10;
				arr[i]=arr[i]%10;
			}
		}
		// If carry is 1, we need to add a 1 at the beginning of array
		if(carry==1){
			arr[0]=1;
		}
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
	}

        int carry = 0;
	for(int i = n-1;i>=0;--i){
		if(i==0&&carry==1){
		arr[i] +=carry;
		break;
		}
		int sum = arr[i]+carry;
		arr[i] = sum%10;
		carry = sum/10;
	}
	    for(int i = 0 ; i < n ; ++i){
	    cout<<arr[i]<<" ";}
	    cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
