/**
* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the * * colors in the order red, white, and blue.
**/

/**Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
**/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int)nums.size();
        
        int f=0, s=0, t=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                f++;
            else if(nums[i]==1)
                s++;
            else
                t++;
        }
        
    for(int i=0;i<f;i++){
        nums[i]=0;        
    }
    for(int i=f;i<f+s;i++){
        nums[i]=1;
    }
    for(int i=f+s;i<f+s+t;i++){
        nums[i]=2;
    }
    }

    
};