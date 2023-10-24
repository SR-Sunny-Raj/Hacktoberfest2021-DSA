// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3




class Solution {
    public int majorityElement(int[] nums) {
        // `m` stores the majority element (if present)
        int m = 0;
 
        // initialize counter `i` with 0
        int i = 0;
 
        // do for each element `A[j]` in the array
        for (int j = 0; j < nums.length; j++)
        {
            // if counter `i` becomes 0
            if (i == 0)
            {
                // set the current candidate to `A[j]`
                m = nums[j];
 
                // reset the counter to 1
                i = 1;
            }
 
            // otherwise, increment the counter if `A[j]` is a current candidate
            else if (m == nums[j]) {
                i++;
            }
            // otherwise, decrement the counter if `A[j]` is a current candidate
            else {
                i--;
            }
        }
 
        return m;
    }     
}    
    
