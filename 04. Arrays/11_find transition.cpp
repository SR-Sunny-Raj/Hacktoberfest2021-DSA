//Problem discription
//Given a sorted array containing only numbers 0 and 1, the task is to find the transition point efficiently. The transition point is the point where “0” ends and “1” begins.
// Input: 0 0 0 1 1
// Output: 3
// Explanation: Index of first 1 is 3




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends

int transitionPoint(int arr[], int n)
{
    // code here
    // Initialise lower and upper bounnds
    int lb = 0, ub = n-1;
 
    // Perform Binary search
    while (lb <= ub)
    {
        // Find mid
        int mid = (lb+ub)/2;
 
        // update lower_bound if mid contains 0
        if (arr[mid] == 0)
            lb = mid+1;
 
        // If mid contains 1
        else if (arr[mid] == 1)
        {
            // Check if it is the left most 1
            // Return mid, if yes
            if (mid == 0
                    || (mid > 0 &&
                       arr[mid - 1] == 0))
                return mid;
 
            // Else update upper_bound
            ub = mid-1;
        }
    }
    return -1;
}
