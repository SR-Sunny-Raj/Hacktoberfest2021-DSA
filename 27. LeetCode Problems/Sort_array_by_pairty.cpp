/*

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.


*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n=a.size(); int curind=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0) { 
            swap(a[i],a[curind]);
            curind++;
        }
    }
        return a;
    }
};
