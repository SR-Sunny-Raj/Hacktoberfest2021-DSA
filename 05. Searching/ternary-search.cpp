#include<bits/stdc++.h>
using namespace std;

//A program to perform ternary search
//Ternary Search is a searching technique, used to determine a position of a specific vale in an (sorted) array in order of O(log3(n)) time

int ternarySearch(int *arr, int left, int right, int find)
{
    //if search range is over then returning -1 as element isn't found
    if (left > right)
    {
        return -1;
    }

    //getting indexs at 1/3 and 2/3 of array's position
    int mid1 = left + (right - left) / 3;
    int mid2 = right -  (right - left) / 3;

    //returning indexes if element is found
    if (arr[mid1] == find)
    {
        return mid1;
    }
    if (arr[mid2] == find)
    {
        return mid2;
    }

    //eliminating search spaces if element is greater than or less than or sits in middle of the marked 1/3 and 2/3 positions
    if (find < arr[mid1])
        return ternarySearch(arr, left, mid1 - 1, find);
    else if (find > arr[mid2])
        return ternarySearch(arr, mid2 + 1, right, find);
    else
        return ternarySearch(arr, mid1 + 1, mid2 - 1, find);
}

int main()
{
    //a random array creation
    int arr[] = {1, 2, 9, 4, 7, 10, 12, 3};
    int n = sizeof(arr) / sizeof(int);

    //sorting the array as ternary search requires sorted array as input
    sort(arr, arr + n);

    //intialising basic search space i.e the endpoints of array
    int left = 0, right = n - 1;

    //getting a random element to be searched
    int find = 4;

    //calling the ternary search function
    //returns -1 is element not found, else index is returned

    int index = ternarySearch(arr, left, right, find);

    if (index == -1)
    {
        cout << "Element not present in array\n";
    }
    else
    {
        cout << "Element is present in the array and occurs at index " << index << " when array is sorted\n";
    }
    return 0;
}