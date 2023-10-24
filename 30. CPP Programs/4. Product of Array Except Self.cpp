class Solution {
public:
    vector<int> productExceptSelf(vector<int>&nums) {
        int n = nums.size();
        vector <int> output;
        if(n < 1)
            return output;
        int product = 1;
        //LEFT section
        for(int i = 0; i < n; i++)
        {
            product *= nums[i];
            output.push_back(product);
        }
        
        //Traverse from right and update the input array
        product = 1;
        for(int i = n-1; i > 0; i--)
        {
            output[i] = output[i-1]*product;
            product *= nums[i];
        }
        output[0] = product;
        return output;    
    }
};

//https://leetcode.com/problems/product-of-array-except-self/
