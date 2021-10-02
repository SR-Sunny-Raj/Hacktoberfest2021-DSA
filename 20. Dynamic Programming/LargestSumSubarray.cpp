#include<bits/stdc++.h>
using namespace std;
 
// Function to calculate Largest Sum Subarray
int maxSubArraySum(vector<int>arr, int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        max_so_far = max(max_so_far,max_ending_here);
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}
 
/*Driver program */
int main()
{
    vector<int>arr{-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Largest Sum Subarray is " << maxSubArraySum(arr, arr.size());
    return 0;
}
