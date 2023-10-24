//Problem link-- https://leetcode.com/problems/majority-element-ii/
//Problem Statement--  Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> ans;
        
        if(nums.size()==1)
        {
            ans.push_back(nums[0]);
            return ans;
        }
        
        int n=nums.size()/3;
        
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        int c=1;
        for(int i=1;i<nums.size();i++)
        {
            if(prev==nums[i])
            {
                c++;
            }
            else
            {
                if(c>n)
                    ans.push_back(prev);
                
                prev=nums[i];c=1;
            }
            
            if(i==nums.size()-1)
            {
                if(c>n)
                    ans.push_back(prev);
            }
            
        }
        
        
        
        return ans;
        
    }
};
