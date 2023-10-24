class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int y=height.size(); 
        int maxarea=0;
        int left=0, right=y-1;
        
        while(left<right){
            maxarea=max(maxarea,(right-left)*min(height[left],height[right]));
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        
        return maxarea;
        
    }
};