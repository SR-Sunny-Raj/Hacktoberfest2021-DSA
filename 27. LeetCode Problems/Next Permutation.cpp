//KHUSHBOO DEV

//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

#include <bits/stdc++.h>

using namespace std;

// function to find the next permutation.

 void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        int j=0;
        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        if(i>=0){
            j=n-1;
            while(j>=0 && nums[j]<=nums[i])
                j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }

int main()
{
    vector<int>nums={3,2,1}; //given vector of integers

    nextPermutation(nums);//function to find the next permutation.

    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
}
