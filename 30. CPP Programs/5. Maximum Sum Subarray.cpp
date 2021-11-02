class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];
        for(auto i: nums)
        {   
            sum += i;
            maxSum = max(sum,maxSum);
            if(sum < 0) sum = 0;       
        }
        return maxSum;
    }
};

//https://leetcode.com/problems/maximum-subarray/
