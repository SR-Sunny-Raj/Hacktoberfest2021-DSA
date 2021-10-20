#include <stdio.h>
 
// Function to find the length of the longest bitonic subarray in an array
void findBitonicSubarray(int arr[], int n)
{
    if (n == 0) {
        return;
    }
 
    // `I[i]` store the length of the longest increasing subarray,
    // ending at `arr[i]`
    int I[n];
    I[0] = 1;
    for (int i = 1; i < n; i++)
    {
        I[i] = 1;
        if (arr[i - 1] < arr[i]) {
            I[i] = I[i - 1] + 1;
        }
    }
 
    // `D[i]` store the length of the longest decreasing subarray,
    // starting with `arr[i]`
    int D[n];
    D[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        D[i] = 1;
        if (arr[i] > arr[i + 1]) {
            D[i] = D[i + 1] + 1;
        }
    }
 
    // consider each element as a peak and calculate LBS
    int lbs_len = 1;
    int beg = 0, end = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (lbs_len < I[i] + D[i] - 1)
        {
            lbs_len = I[i] + D[i] - 1;
            beg = i - I[i] + 1;
            end = i + D[i] - 1;
        }
    }
 
    // print the longest bitonic subarray
    printf("The length of the longest bitonic subarray is %d\n", lbs_len);
    printf("The longest bitonic subarray indices is [%d, %d]", beg, end);
}
 
int main(void)
{
    int A[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
    int n = sizeof(A) / sizeof(A[0]);
 
    findBitonicSubarray(A, n);
 
    return 0;
}


/*
for example-
Longest bitonic subarray of the sequence { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 } is { 4, 5, 9, 10, 8, 5, 3 }
 
For sequences sorted in increasing or decreasing order, the output is the same as the input sequence, i.e.,
 
[1, 2, 3, 4, 5] ——> [1, 2, 3, 4, 5]
[5, 4, 3, 2, 1] ——> [5, 4, 3, 2, 1]
*/
