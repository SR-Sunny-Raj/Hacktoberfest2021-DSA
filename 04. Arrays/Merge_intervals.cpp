// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            return intervals;
        }
        vector<vector<int>>ret;
        sort(intervals.begin(),intervals.end());
        int firstInterval=intervals[0][0];
        int lastInterval=intervals[0][1];
        for(auto a=1; a<intervals.size();a++){
           if(lastInterval>=intervals[a][0]){
               if(lastInterval<intervals[a][1]){
                    lastInterval=intervals[a][1];
               }
           }
            else{
                ret.push_back({firstInterval,lastInterval});
                firstInterval=intervals[a][0];
                lastInterval=intervals[a][1];
            }
        }
        ret.push_back({firstInterval,lastInterval});
        return ret;
    }
};
