/* Disjoint Smaller Partions */
/*
    Given an integer array nums, partition it into two (contiguous) subarrays part1 and part2 so that:

        • Concatenation of part1 & part2 MUST be original array, it means
          you have to divide array in two parts - parition
        • Every element in part1 is less than or equal to every element in part2.
        • part1 and part2 are non-empty.
        • part1 has the smallest possible size.

    Find the length of part1 after such a partitioning.

    Example:
    Array = [4, 1, 2, 5, 7]
    Answer = 3
    Explanation:
    if we divide the array as [4, 1, 2] & [5, 7] 
    then all elements in part1 are less than or equal to those in part2

    [4, 1, 2, 5] & [7] is also one answer but as per question we need minimal length of part 1

    ** APPROACH
    suppose given array is x1, x2, x3, x4, ...... xn,
    If we divide array into two parts namely left and right (partitioning at k)
    LEFT = {x1, x2, x3.... xk}
    RIGHT = {xk+1, xk+2.... xn}

    We only have to make sure left max(LEFT) <= min(RIGHT)
    and for this we can use array to store max of elements till ith index
    and another to store from min elements from last

    For example
    A = {5,0,3,6,8}
    then max Array = {5,5,5,6,8}
    min Array = {0,0,3,6,8}

    Now we only have to find the first index where max[i] <= min[i+1] and i is answer (if 1-based indexing)

    **CODE:
*/

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int n = 6;
    int nums[n] = {4,1,3,2,6,5};
    int ma[n],mi[n];     //ma and mi are max and min arrays respectively
    ma[0] = nums[0];

    for(int i=1;i<n;i++)
        ma[i] = max(ma[i-1],nums[i]);
    
    mi[n-1] = nums[n-1];

    for(int i=n-2;i>=0;i--)
        mi[i] = min(mi[i+1],nums[i]);
    int ans = 1;

    for(int i=0;i<n-1;i++)
    {
        if(ma[i]<=mi[i+1])
        {
            ans = i+1;          // +1 as indexing is 0-based
            break;
        }
    }
    cout<<ans;
}
