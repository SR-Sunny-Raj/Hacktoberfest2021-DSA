// Problem Link: https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0, currWater=0;
        int i = 0, j = height.size()-1;
        while(i<j)
        {
            if(height[i]>height[j])
                currWater = (j-i)*height[j--];
            else
                currWater = (j-i)*height[i++];
            maxWater = max(currWater, maxWater);
        }
        return maxWater;
    }
};
