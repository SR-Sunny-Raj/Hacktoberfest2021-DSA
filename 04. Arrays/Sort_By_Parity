class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        vector<int> k(nums.size());        
        int j=0,r=1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                k[j]=nums[i]; j+=2;
            }
            else 
            {
                k[r]=nums[i]; r+=2;
            }
        }
        
        return k;
    }
};
