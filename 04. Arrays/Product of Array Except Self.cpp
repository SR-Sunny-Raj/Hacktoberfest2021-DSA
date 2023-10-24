/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/

/*
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

/*
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

#include<iostream>
using namespace std;
int main()
{
    int a[100],b[100],n,mult=1;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mult = mult * a[i];
    }
    for(int i=0;i<n;i++)
    {
        b[i] = mult/a[i];
        cout<<b[i]<<" ";
    }
}
