"""
56. Merge Intervals
Link:- https://leetcode.com/problems/merge-intervals/

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

"""

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals=sorted(intervals)
        mi=intervals[0][0]
        ma=intervals[0][1]
        ans=[]
        for i in intervals:
            if mi<=i[0]<=ma or mi<=i[1]<=ma:
                mi=min(mi,i[0])
                ma=max(ma,i[1])
            else:
                ans.append([mi,ma])
                mi=i[0]
                ma=i[1]
        ans.append([mi,ma])
        return ans
