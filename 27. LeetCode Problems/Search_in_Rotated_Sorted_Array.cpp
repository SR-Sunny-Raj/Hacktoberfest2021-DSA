//question: https://leetcode.com/problems/search-in-rotated-sorted-array/
//binary Search 
//time complexity O(logn)
#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int mid = (i+j) / 2;
            if (target == nums[mid])
                return mid;
            // there exists rotation;
            // the middle element is in the left part of the array
            if (nums[mid] > nums[j]) {
                if (target < nums[mid] && target >= nums[i])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            // there exists rotation;
            // the middle element is in the right part of the array
            else if (nums[mid] < nums[i]) {
                if (target > nums[mid] && target <= nums[j])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
            // there is no jotation;
            // just like normal binary search
            else {
                if (target < nums[mid])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
        }
        return -1;
    }
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    int target;
    cin>>target;
    cout<<search(nums,target);
    return 0;
}
