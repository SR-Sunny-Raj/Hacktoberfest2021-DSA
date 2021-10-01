#include<iostream>
using namespace std;

//Function to find maximum sum contiguous subarray in a given set of integers

int kadane(int arr[], int n)
{
	//stores maximum sum subarray found so far
	 
	int max_so_far = 0;
	 
	//stores the maximum sum of subarray ending at the current position

	int max_ending_here = 0;

	//traverse the given array

	for (int i = 0; i < n; i++)
	{
    	/* update maximum sum of subarray "ending" at index i (by adding the current element to maximum sum ending at previous index i-1) */

    	max_ending_here = max_ending_here + arr[i];
 
    	/* if maximum sum is negative, set it to 0 (which represents an empty sub-array) */
    	if(max_ending_here < 0)
    	{
        	max_ending_here = 0;
    	}
     	 
    	//update result if current subarray sum is found to be greater
    	if(max_so_far < max_ending_here)
    	{
        	max_so_far = max_ending_here;    
    	}
	return max_so_far;
}

int main()
{
 	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 	int n = sizeof(arr)/sizeof(arr[0]);
 	cout << "Maximum sum contiguous subarray is "<<kadane(arr, n);
 	return 0;
}
