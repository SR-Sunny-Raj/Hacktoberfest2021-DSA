class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> arr(2);
    for(int i = 0;i<nums.size();i++){
        int ans;
        ans = nums[i]+nums[i+1];
        if(ans == target)
        arr[0]=i;
        arr[1]=i+1;
        return arr;
        else{
            for(int j = i+1;j<nums.size() - i; j++){
                int ans1;
                ans1 = nums[j] == nums[j+1];
                i++;
                if(ans1 == target){
                    arr[0]= j;
                    arr[1]= j+1;
                }
                    
             }
         }
       }
    return arr;
    }
}
