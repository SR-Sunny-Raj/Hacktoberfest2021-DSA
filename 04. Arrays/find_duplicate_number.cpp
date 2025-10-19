/**
 * Author: Mujeeb Arshad
 * Problem: Find the Duplicate Number (LeetCode 287)
 * Description: Given an array nums containing n + 1 integers where each integer is in the range [1, n],
 * return the duplicate number without modifying the array and using only O(1) extra space.
 * Approach: Floyd's Tortoise and Hare (Cycle Detection)
 */

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Finding intersection point inside the cycle
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Finding entrance to the cycle (duplicate number)
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> nums1 = {1, 3, 4, 2, 2};
    vector<int> nums2 = {3, 1, 3, 4, 2};
    vector<int> nums3 = {3, 3, 3, 3, 3};

    cout << "Duplicate in nums1: " << findDuplicate(nums1) << endl; // 2
    cout << "Duplicate in nums2: " << findDuplicate(nums2) << endl; // 3
    cout << "Duplicate in nums3: " << findDuplicate(nums3) << endl; // 3

    return 0;
}
