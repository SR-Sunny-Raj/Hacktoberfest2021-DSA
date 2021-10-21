// Leetcode Problem - 1492. The kth Factor of n

/*Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.
Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.*/

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        if(ans.size()<k)
            return -1;
        else
            return ans[k-1];
    }
};
