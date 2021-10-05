// C++ program to reverse every sub-array formed by 
// consecutive k elements 
#include <iostream> 
using namespace std; 

// Function to reverse every sub-array formed by 
// consecutive k elements 
void reverse(int arr[], int n, int k) 
{ 
	for (int i = 0; i < n; i += k) 
	{ 
		int left = i; 

		// to handle case when k is not multiple of n 
		int right = min(i + k - 1, n - 1); 

		// reverse the sub-array [left, right] 
		while (left < right) 
			swap(arr[left++], arr[right--]); 

	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
	int k = 3; 

	int n = sizeof(arr) / sizeof(arr[0]); 

	reverse(arr, n, k); 

	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 

	return 0; 
} 
