class Solution {
    int findIntegers(int num) {
        vector<int> noOfNum(32, 0);
        noOfNum[0] = 1;
        noOfNum[1] = 2;
        
        for (int i = 2; i < 32; i++) {
            noOfNum[i] = noOfNum[i - 1] + noOfNum[i - 2];
        }
        
        int prev = 0, ans = 1;
        for (int i = 31; i >= 0; i--) {
            if ((num & (1 << i)) == 0) {
                prev = 0;
            }
            else {
                ans += noOfNum[i];
                if (prev == 1) {
                    ans--;
                    break;
                }
                prev = 1;
            }
        }
        
        return ans;
    }
};