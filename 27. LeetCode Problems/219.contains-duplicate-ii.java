import java.util.HashSet;

/*
 * @lc app=leetcode id=219 lang=java
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> s = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (i > k)
                s.remove(nums[i - k - 1]);
            if (!s.add(nums[i]))
                return true;
        }
        return false;

    }
}
// @lc code=end
