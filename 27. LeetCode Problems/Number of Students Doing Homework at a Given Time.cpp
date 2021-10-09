// Difficulty : Easy
// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/


class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size(), ans = 0;       //defining variable
        for (int i=0; i<n; i++){
            if (startTime[i]<=queryTime && queryTime<=endTime[i]) ans++; // if condition true, increment ans
        }
        return ans;         // returning ans
    }
};
