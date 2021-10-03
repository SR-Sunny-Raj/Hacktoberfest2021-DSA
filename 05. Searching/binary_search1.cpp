#include <iostream>
using namespace std;
//iterative binary search
int binarySearch(int A[], int low, int high, int x)
	{  
		while (low <= high)
		{
			// we find the mid value in the search space and
			// compares it with key value

			int mid = (low + high) / 2;

			// overflow can happen. Use:
			// int mid = low + (high - low) / 2;
			// int mid = right - (high - low) / 2;

			// key value is found
			if (x == A[mid]) {
				return mid;
			}

			// discard all elements in the right search space
			// including the mid element
			else if (x < A[mid]) {
				high = mid - 1;
			}

			// discard all elements in the left search space
			// including the mid element
			else {
				low = mid + 1;
			}
		}

		// x doesn't exist in the array
		return -1;
	}
int main()
{
    int n,key,i;
    cout<<"Enter size of array):"<<endl;
    cin>>n;
    int arr[n];
    cout << "Please enter "<<n<<" numbers (with spaces between them): ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter number for searching: ";
    cin >> key;
    int low = 0;
    int high= n - 1;
    int index = binarySearch(arr, low, high, key);

    if (index != -1) {
       cout<<"Element found at index "<<index;
    } else {
        cout<<"Element not found in the array";
    }
    return 0;
}
