/*

LeetCode problem : https://leetcode.com/problems/sliding-window-maximum/

Topic: Dequeue, Sliding window

PROBLEM STATEMENT-

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window.
Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    int n = nums.size();

    //The idea of the algorithm is to maintain the elements in decreasing order in the deque.
    //In this way, the front of dequeue will always be the maximum.

    for(int i=0;i<n;i++){
        //to maintain the decreasing order, pop from back of deque till back is smaller than current element to be pushed.
        while(!dq.empty()&&nums[dq.back()]<nums[i])
            dq.pop_back();

        //insert the current element in deque when proper position is found.
        dq.push_back(i);

        //If the element get out from current window, we should remove it
        if(dq.front()<=i-k) dq.pop_front();

        //pushing the max of current window
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main(){
    int n,k;
    vector<int> nums;
    
    //input the size of array and length of window
    cin>>n>>k;
    
    //input the array
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    //calling the function to get the maximum values in each window
    vector<int> ans = maxSlidingWindow(nums,k);

    //display the results
    for(int i:ans)
        cout<<i<<" ";
}