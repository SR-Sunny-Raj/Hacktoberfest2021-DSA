# This simple program checks if a string is a palindrome or not.
# A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward or forward.
# For example, the following words are palindromes: madam, racecar, and radar.
# The following words are not palindromes: pop, and racecar.
# The program takes in a string and checks if it is a palindrome or not.
# Problem description: https://leetcode.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x: int) -> bool:
      x=str(x)
      if x[::-1]==str(x):
        return True
      else:
        return False

ans=Solution()

ans.isPalindrome(-121)