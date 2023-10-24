"""
43. Multiply Strings

Link:- https://leetcode.com/problems/multiply-strings/

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

"""

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        
        t=1
        d={'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}
        f1=0
        for i in num1[::-1]:
            f1+=d[i]*t
            t*=10
        
        t=1
        f2=0
        for i in num2[::-1]:
            f2+=d[i]*t
            t*=10
        ans=f1*f2
        
        p={0:'0',1:'1',2:'2',3:'3',4:'4',5:'5',6:'6',7:'7',8:'8',9:'9'}
        fi=""
        if ans==0:
            return '0'
        while ans>0:
            fi+=p[ans%10]
            ans//=10
        return fi[-1::-1]
