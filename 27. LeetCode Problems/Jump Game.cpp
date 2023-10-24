class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0,reach=0;
        while(i<nums.size() &&i<=reach){
            reach=max(i+nums[i],reach);
            i++;
        }
        if(i==nums.size()){
            return true;
        }
        return false;
    }
};
