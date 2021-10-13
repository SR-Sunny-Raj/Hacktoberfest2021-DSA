//Problem link:
//https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        if(nums.size() < 3)
            return {};
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        
        
        for(int i=0; i<nums.size()-2; i++)
        { 
            if(i==0 || (nums[i] != nums[i-1]))
            {
                int l=i+1, h=nums.size()-1;
                while(l<h)
                {
                    int sum = nums[i] + nums[l] + nums[h]; 
                    if(sum==0)
                    {
                        ans.push_back({nums[i], nums[l], nums[h]});
                        
                        while(l<h && nums[l] == nums[l+1]) l++;
                        while(l<h && nums[h] == nums[h-1]) h--;
                        
                        l++; h--;
                    }
                    else if(sum < 0) l++;
                    else h--;
                }
            }
        }
        return ans;
    }
};
