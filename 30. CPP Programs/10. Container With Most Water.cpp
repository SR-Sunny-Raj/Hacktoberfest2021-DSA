#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxArea(int height[], int j) 
    {
        int i=0;
        int maxArea=0;
        while(i<j)
        {
            int currArea=min(height[i],height[j])*(j-i);
            maxArea=max(currArea,maxArea);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};

int main()
{
    int hist[] = {1,2,1};
    int n = sizeof(hist) / sizeof(hist[0]);
    Solution s;
    cout << "Maximum area is " << s.maxArea(hist, n - 1);
}
