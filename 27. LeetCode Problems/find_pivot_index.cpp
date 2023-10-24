/*
    Problem link
    https://leetcode.com/problems/find-pivot-index/
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0; i<nums.size(); i++){
            if(i==0){if(nums[nums.size()-1]-nums[i]==0)
                return 0;
                else continue;
            }
            else if(nums[i-1]==nums[nums.size()-1]-nums[i]) return i;
            else continue;
        }
        return -1;
    }
};