#include <bits/stdc++.h>

using namespace std;
// prefix Sum approach

int largestSubarrays(int arr[], int n)
{
    // Prefix Sum
    int prefix[100] = {0};
    prefix[0] = arr[0]; // i not = 0 because i =0 ==> 0-1=-1
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int largest_sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            int subarraySum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];

            largest_sum = max(largest_sum, subarraySum);
        }
    }

    return largest_sum;
}

int main()
{

    // int arr[] = {-5, 4, 6, -3, 4, -1};

    int arr[] = {1, -2, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << largestSubarrays(arr, n) << endl;
    return 0;
}