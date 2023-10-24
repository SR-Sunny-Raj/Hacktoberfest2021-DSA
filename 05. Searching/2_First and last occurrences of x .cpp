/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

 

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
Example 2:

Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect 
square, so its square root is 2.
 

Your Task:
You don't need to read input or print anything. The task is to complete the function floorSqrt() which takes x as the input parameter and return its square root.
Note: Try Solving the question without using sqrt Function.

 

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

 
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root

class Solution
{
public:
    long long int floorSqrt(long long int x)
    {  
        
        
        // Base cases
        if (x == 0 || x == 1)
        return x;
        
        // Do Binary Search for floor(sqrt(x))
        int start = 1, end = x, ans;
        while (start <= end) {
        int mid = (start + end) / 2;
  
        // If x is a perfect square
        if (mid * mid == x)
            return mid;

         // Since we need floor, we update answer when
        // mid*mid is smaller than x, and move closer to
        // sqrt(x)
        if (mid <= x / mid) {
            start = mid + 1;
            ans = mid;
          }

        else // If mid*mid is greater than x
            end = mid - 1;
        }
     return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
