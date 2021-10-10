/*
Problem statement

Given a sorted array containing only 0s and 1s, find the transition point. 


Example 1:

Input:
N = 5
arr[] = {0,0,0,1,1}
Output: 3
Explanation: index 3 is the transition 
point where 1 begins.


Example 2:

Input:
N = 4
arr[] = {0,0,0,0}
Output: -1
Explanation: Since, there is no "1",
the answer is -1.


Your Task:
You don't need to read input or print anything. The task is to complete the function transitionPoint() that takes array and N as input parameters and returns the 0 based index of the position where "0" ends and "1" begins. If array does not have any 1s, return -1. If array does not have any 0s, return 0.


Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 500000
0 ≤ arr[i] ≤ 1
*/

// Solution

#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    int firstZero(int arr[], int low, int high) {
        if (high >= low) {
            int mid = low + (high - low) / 2;

            // Check if mid element is first 0
            if ((mid == 0 || arr[mid - 1] == 1) && arr[mid] == 0) 
                return mid;

            // If mid element is not 0
            if (arr[mid] == 1) 
                return firstZero(arr, (mid + 1), high);

            // If mid element is 0, but not first 0
            else
                return firstZero(arr, low, (mid - 1));
        }
        return -1;
    }
    int countZeroes(int arr[], int n) {
        // Find index of first zero in given array
        int first = firstZero(arr, 0, n - 1);

        // If 0 is not present at all, return 0
        if (first == -1) 
            return 0;

        return (n - first);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countZeroes(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
