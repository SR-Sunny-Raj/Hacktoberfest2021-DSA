/**
2. Third largest element 
Given an array of distinct elements. Find the third largest element in it. 

Example 1:

Input:
N = 5
A[] = {2,4,1,3,5}
Output: 3
Example 2:

Input:
N = 2
A[] = {10,2}
Output: -1
Your Task:
Complete the function thirdLargest() which takes the array a[] and the size of the array, n, as input parameters and returns the third largest element in the array. It return -1 if there are less than 3 elements in the given array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
**/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	//Function to count the frequency of all elements from 1 to N in the array.
	void frequencyCount(vector<int> &arr, int N, int P)
	{
		// code here
		//if number of elements are less than 3 then return -1
		if(N<3)
		   cout<<"Invalid input"<<endl;
		// Initialize first, second and third Largest element
		int first = arr[0], second = INT_MIN, third = INT_MIN;
		// Traverse array elements to find the third Largest
                for (int i = 1; i < N ; i ++)
                 {
                       /* If current element is greater than first,
                         then update first, second and third */
                     if (arr[i] > first)
                       {
                          third  = second;
                         second = first;
                         first  = arr[i];
                     }
 
                /* If arr[i] is in between first and second */
                    else if (arr[i] > second)
                    {
                    third = second;
                    second = arr[i];
                    }
 
                  /* If arr[i] is in between second and third */
                 else if (arr[i] > third)
                 third = arr[i];
            }
 
	     cout<<"Third largest element is "<<third<<endl;
	}
};

// { Driver Code Starts.

int main()
{
	long long t;

	//testcases
	cin >> t;

	while (t--)
	{

		int N, P;
		//size of array
		cin >> N;

		vector<int> arr(N);

		//adding elements to the vector
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		cin >> P;
		Solution ob;
		//calling frequncycount() function
		ob.frequencyCount(arr, N, P);

		//printing array elements
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}

// } Driver Code Ends
