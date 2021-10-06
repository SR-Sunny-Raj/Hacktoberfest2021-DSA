//  Question: Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

// Solved using Cycle Sort which is an evergreen method for finding number if they are ordered from 1 to n order. 

void swap(vector<int>& nums, int a ,int b)
{
    int temp = nums[a];
    nums[a]= nums[b];
    nums[b]=temp;
}

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int i = 0;
        while( i < nums.size()) {
            int correct_index = nums[i] -1;
            if( nums[i] != nums[correct_index]){
                swap(nums,i,correct_index);
            }
            else{
                i++;
            }
        }
        vector <int> res;
        for ( int index = 0 ; index < nums.size(); index++) {
            if(nums[index]!= index +1) {
                res.push_back(index+1);
            }
        }
        return res;
    }
};