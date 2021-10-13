//Prblem Link:
//https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>> store;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int new_target = target - nums[i] - nums[j];
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    int sum = nums[left] + nums[right];
                    if(sum < new_target)
                        left++;
                    else if(sum > new_target)
                        right--;
                    else{
                        store.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                }
            }
        }
        
        for(auto i : store)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
