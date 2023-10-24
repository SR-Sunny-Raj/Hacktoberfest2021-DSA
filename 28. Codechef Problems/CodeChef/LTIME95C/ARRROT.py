"""

Problem Name: Array Rotation
CodeChef Link: https://www.codechef.com/LTIME95C/problems/ARRROT/
Problem Code: ARRROT

"""

n = int(input())
li = list(map(int, input().split()))
q = int(input())
li2 = list(map(int, input().split()))

s = sum(li)
x = 0

for i in li2:
    x = (2 * s)
    s = x
    
    print(x % (1000000007))
