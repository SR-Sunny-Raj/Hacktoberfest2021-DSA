/*
    Problem Link
    https://leetcode.com/problems/find-the-highest-altitude/
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHieght=0, a=0;
        for(int i=0; i<gain.size(); i++){
            a+=gain[i];
            maxHieght=max(maxHieght, a);
        }
        return maxHieght;
    }
};