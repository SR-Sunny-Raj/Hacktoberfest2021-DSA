Problem-Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity
link-https://leetcode.com/problems/search-insert-position/
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
  
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
  
 Code-
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int l=0;
    int r=nums.size()-1;
    while(l<r){
            int mid=l+(r-l)/2;
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid])
                r=mid;
            else
                l=mid+1;          
            
        }
        return nums[l] < target ? l + 1: l;      
    }
};
