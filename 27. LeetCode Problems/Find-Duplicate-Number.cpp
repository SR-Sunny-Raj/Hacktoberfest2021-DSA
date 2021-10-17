//Problem Link-- https://leetcode.com/problems/find-the-duplicate-number/
// The Problem is solved using the Linked List Cycle meet method
// using Two Pointers


class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
       int slow=nums[0];int fast=nums[0];
        
        
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        
            fast=nums[0];
        
        while(slow!=fast)
        {
            fast=nums[fast];slow=nums[slow];
        }
        return fast;
    
        
    }
};
