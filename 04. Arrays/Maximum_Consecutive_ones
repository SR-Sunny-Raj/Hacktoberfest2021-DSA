class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> k(nums.size()); 
        int j=0;
        for(int i=0;i<nums.size();i++) 
        {            
            if(nums[i]==1) 
                     k[j]++;               
            else  j++;  
        }
        
          return *max_element(k.begin(),k.end());
    }
};
