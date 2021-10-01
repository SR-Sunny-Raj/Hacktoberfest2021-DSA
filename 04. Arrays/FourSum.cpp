/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n

a, b, c, and d are distinct.

nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0

Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8

Output: [[2,2,2,2]]

Constraints:

1 <= nums.length <= 200

-10^9 <= nums[i] <= 10^9

-10^9 <= target <= 10^9

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<tuple<int,int,int,int>>s;
        vector<vector<int>>ans;
        if(nums.size()<4)
            return ans;
        int a,b,c,d,n=nums.size();
        sort(nums.begin(),nums.end());
        for(a=0;a<n-3;a++){
            for(b=a+1;b<n-2;b++){
              c=b+1;
                d=n-1;
                while(c<d){
                int x=nums[a]+nums[b]+nums[c]+nums[d];
                if(x==target){
                    s.insert(make_tuple(nums[a],nums[b],nums[c],nums[d]));
                    c++;
                    d--;
                }
                
                else if(x<target)
                    c++;
                else
                    d--;
                }
            }
        }
        int size=s.size();
         vector<vector<int>> v(size,vector<int> (4));
        int i=0;
        for(auto it:s){
            v[i][0]=get<0>(it);
            v[i][1]=get<1>(it);
            v[i][2]=get<2>(it);
            v[i][3]=get<3>(it);
            i++;
        }
        return v;
    }
};
