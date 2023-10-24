"""
7. Reverse Integer #969

Link:- https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
 

Constraints:

-231 <= x <= 231 - 1

"""

class Solution:
    def reverse(self, x: int) -> int:
        x=str(x)
        try:
            if x[0]=='-':
                p=(x[1:])[-1::-1]
                p=int('-'+p)
                if p in range(-2**31,2**31+1):
                    return p
                else:
                    return 0
            p=int(x[-1::-1])
            if p in range(-2**31,2**31+1):
                return p
            else:
                return 0
        except:
            return 0
