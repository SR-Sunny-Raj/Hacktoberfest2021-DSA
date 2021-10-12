"""
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. 
i.e., after this step, s may become s = x + y or s = y + x.

Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Example:
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now and the result string is "rgeat" which is s2.
As there is one possible scenario that led s1 to be scrambled to s2, we return true.
"""
from collections import defaultdict

def scrambledString(a,b):
    if a==b:
        return True
    if len(a)<=1:
        return False
    key=a+" "+b
    if mp[key]!= -1:
        return mp[key]
    n=len(a)
    flag=False

    for i in range(1,n):
        print(flag,i)
        #condition 1 or condition 2 
        print(a[:i],b[n-i:],a[i:],b[:n-i])
        print(a[:i],b[:i],a[i:],b[i:])
        if (scrambledString(a[:i],b[n-i:]) and scrambledString(a[i:],b[:n-i])) or (scrambledString(a[:i],b[:i]) and scrambledString(a[i:],b[i:])):
            flag=True
            break
    mp[key]=flag
    return flag

a="abb"
b="bba"
mp=defaultdict(lambda:-1)

if len(a)!=len(b):
    print("False")
if a=="" and b=="":
    print("True")

print(scrambledString(a,b))