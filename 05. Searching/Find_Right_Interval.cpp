// link to problem: https://leetcode.com/problems/find-right-interval/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> m;
        vector<int> ans(intervals.size());
        for(int i=0;i<intervals.size();i++){
            m[intervals[i][0]]=i;
        }
        for(int i=0;i<intervals.size();i++){
            ans[i]=m.lower_bound(intervals[i][1])!=m.end()?m.lower_bound(intervals[i][1])->second:-1;
        }
        return ans;
    }
};