#include <bits/stdc++.h>
using namespace std;

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth largest element and return using this function
int kthLargest(int arr[], int l, int r, int k)
{
    //Use C++ sorting
    sort(arr, arr + r + 1);
    //return r-k+1 indexed element as kth largest element
    return arr[r - k + 1];
}

int main()
{

    int number_of_elements;
    cin >> number_of_elements;
    int a[number_of_elements];

    for (int i = 0; i < number_of_elements; i++)
        cin >> a[i];

    int k;
    cin >> k;
    cout << kthLargest(a, 0, number_of_elements - 1, k) << endl;

    return 0;
}
