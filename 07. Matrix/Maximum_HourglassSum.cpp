/*
Problem Statement :-

Given a  2D Array, :

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
An hourglass is a subset of values with indices falling in this pattern in this graphical representation:

a b c
  d
e f g
An hourglass sum is the sum of an hourglass' values. Calculate the hourglass sum for every hourglass , then print the maximum hourglass sum.

Example


-9 -9 -9  1 1 1 
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0
 
The  hourglass sums are:

-63, -34, -9, 12, 
-10,   0, 28, 23, 
-27, -11, -2, 10, 
  9,  17, 25, 18
  
The highest hourglass sum is  from the hourglass beginning at row 1, column 2:

0 4 3
  1
8 6 6


Function Description

Complete the function hourglassSum 

hourglassSum has the following parameter(s):

int arr[6][6]: an array of integers

Returns

int: the maximum hourglass sum

*/

//Solution

int hourglassSum(vector<vector<int>> arr)
{
    int maxsum = INT_MIN;
    for (int r = 0; r <= 3; r++)
    {
        for (int c = 0; c <= 3; c++)
        {
            int sum = arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 1] + arr[r + 2][c] +
                      arr[r + 2][c + 1] + arr[r + 2][c + 2];
            maxsum = max(sum, maxsum);
        }
    }
    return maxsum;
}
