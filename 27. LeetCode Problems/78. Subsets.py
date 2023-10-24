"""
78. Subsets

Link:- https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

"""

  li=[]
  for i in range(2**(len(nums)) ):
      li.append( '0'*(len(nums)-len(bin(i)[2:])) + bin(i)[2:] )
  ans=[]
  for i in li:
      s=[]
      for j in range(len(i)):
          if i[j]=='1':
              s.append(nums[j])
      ans.append(s)
  return ans
