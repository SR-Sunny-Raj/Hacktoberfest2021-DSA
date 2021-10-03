/*
Problem Description: Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
Expected Time Complexity: O(N)

Sample Input:
1
6
4 10 2 3 20 9
3

Sample Output:
4

Explanation :
3rd smallest element in the given array is 4.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr, arr+r+1);
        return arr[k-1];
    }
};
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        
        for(int i=0;i<n;i++)
            cin >> a[i];
            
        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, n-1, k)<<endl;
    }
    return 0;
} 