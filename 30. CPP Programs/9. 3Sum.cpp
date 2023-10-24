class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {}; //cannot look for triplets so send empty vector
        vector <vector<int>> result;
        sort(nums.begin(),nums.end()); // sort in order to skip duplicate numbers 
        for(int i = 0; i < n-2; i++) // n- 2 because we have to look for two more elements; avoiding overflow
        {
            if(i == 0 || nums[i] != nums[i-1]) //if it's the 1st element or if it doesn't have a duplicate 
            {
                int j = i + 1, k = n-1;// two variables one ahead and another from the last one
                while(j < k) //these two points do not meet
                {
                    int sum = nums[i] + nums[j] + nums[k]; //add them 
                    if(sum ==0) //check if they're being added to zero
                    {
                        result.push_back({nums[i], nums[j], nums[k]}); //then push them in as a vector
                        while(j < k && nums[j] ==  nums[j + 1]) j++; // skip for j duplicate
                        while( j < k && nums[k] == nums[k -1]) k--; //skip for k duplicate 
                        j++;k--;// move ahead now
                    }
                    else if(sum > 0) k--; // remove the largest element as it is sorted
                    else j++; // if sum < 0  remove fhe smallest element as it is sorted 
                }
                    
            }
        }
        return result;
        
    }
};
