#define INF 1e3
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]) nums[i-1]=INF;
        }
        int k{0};
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==INF) continue;
            nums[k++]=nums[i];
        }
        return k;
    }
};
