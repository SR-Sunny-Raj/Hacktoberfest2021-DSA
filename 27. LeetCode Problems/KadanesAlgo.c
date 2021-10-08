#include <stdio.h>
#include <stdlib.h>
#define MIN -100000

int KadaneAlgo(int *arr, int n)
{
    int maxSoFar = MIN, max = 0;
    for (int i = 0; i < n; i++)
    {
        max += arr[i];
        if (maxSoFar < max)
            maxSoFar = max;
        if (max < 0)
            max = 0;
    }
    return maxSoFar;
}

int main()
{
    int n, *arr;
    printf("Enter size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Max Contiguous Sum: %d", KadaneAlgo(arr, n));
    return 0;
}