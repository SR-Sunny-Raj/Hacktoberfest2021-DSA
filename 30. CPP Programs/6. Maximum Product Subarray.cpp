class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = nums[0];
        int prev_max = nums[0], prev_min = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int prev_max1 = prev_max;
            prev_max = max({nums[i], nums[i]*prev_max, nums[i]*prev_min});
            prev_min = min({nums[i], nums[i]*prev_max1, nums[i]*prev_min});
            max1 = max(max1,prev_max);
        }
        return max1;
    }
};

//https://leetcode.com/problems/maximum-product-subarray/
