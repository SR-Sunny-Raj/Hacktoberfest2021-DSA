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
