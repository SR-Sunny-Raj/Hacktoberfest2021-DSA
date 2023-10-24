
#include <bits/stdc++.h>
using namespace std;

// Function to find out the number of
// candies every person received
void candies(int n, int k)
{

	// Count number of complete turns
	int count = 0;

	// Get the last term
	int ind = 1;

	// Stores the number of candies
	int arr[k];

	memset(arr, 0, sizeof(arr));

	int low = 0, high = n;

	// Do a binary search to find the number whose
	// sum is less than N.
	while (low <= high) {

		// Get mide
		int mid = (low + high) >> 1;
		int sum = (mid * (mid + 1)) >> 1;

		// If sum is below N
		if (sum <= n) {

			// Find number of complete turns
			count = mid / k;

			// Right halve
			low = mid + 1;
		}
		else {

			// Left halve
			high = mid - 1;
		}
	}

	// Last term of last complete series
	int last = (count * k);

	// Subtract the sum till
	n -= (last * (last + 1)) / 2;

	int i = 0;

	// First term of incomplete series
	int term = (count * k) + 1;

	while (n) {
		if (term <= n) {
			arr[i++] = term;
			n -= term;
			term++;
		}
		else {
			arr[i] += n;
			n = 0;
		}
	}

	// Count the total candies
	for (int i = 0; i < k; i++)
		arr[i] += (count * (i + 1))
			+ (k * (count * (count - 1)) / 2);

	// Print the total candies
	for (int i = 0; i < k; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int n = 7, k = 4;
	candies(n, k);

	return 0;
}
