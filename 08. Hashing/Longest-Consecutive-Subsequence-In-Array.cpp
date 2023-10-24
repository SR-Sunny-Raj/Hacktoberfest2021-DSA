//Problem-Statement : Given an array of integers, 
//find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Time Complexity - O(n)

//Example - Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
//Output: 4
//Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements


#include <bits/stdc++.h>
using namespace std;
 
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> H;
    int ans = 0;
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        H.insert(arr[i]);
  
  
    for (int i = 0; i < n; i++) // check each possible sequence from the start then update optimal length
    {
        
        if (H.find(arr[i] - 1) == H.end()) // if current element is the starting element of a sequence.
        {
            
            int j = arr[i]; // Then check for next elements in the sequence.
            while (H.find(j) != H.end())
                j++;
 
            ans = max(ans, j - arr[i]); //If length is more, Update the optimal length.
        }
    }
    return ans;
}
 
int main()
{
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
    int n = sizeof arr / sizeof arr[0];
    cout<< findLongestConseqSubseq(arr, n);
    return 0;
}
