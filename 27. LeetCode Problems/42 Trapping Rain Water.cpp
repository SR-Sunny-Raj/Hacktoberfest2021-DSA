/* Trapping Rain Water
link :https://leetcode.com/problems/trapping-rain-water/
*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        long long res = 0;

		int l = 0, r = n - 1, r_max = 0, l_max = 0;

		while (l <= r)
		{
			if (height[l] <= height[r])
			{
				if (height[l] >= l_max)
				{
					l_max = height[l];
				}
				else
				{
					res += l_max - height[l];
				}

				l++;
			}
			else
			{
				if (height[r] >= r_max)
				{
					r_max = height[r];
				}
				else
				{
					res += r_max - height[r];
				}
				r--;
			}
		}

		return res;
        
        
    }
};
