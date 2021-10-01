class Solution {
public:
    int search(vector<int>& nums, int target) {
       if(nums.size() == 0) return -1;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        
        int start = left; // lowest index or the pivot point
        left = 0;
        right = nums.size() - 1;
        
        if(target >= nums[start] && target <= nums[right])
            left = start;
        else    right= start;
        
        while (left <= right)
        {
            int midpoint = left + (right-left)/2;
            if(nums[midpoint] == target)return midpoint;
            else if (nums[midpoint] < target) left = midpoint + 1;
            else right = midpoint - 1;
            
        }
        return -1;
    }
};

//https://leetcode.com/problems/search-in-rotated-sorted-array/
