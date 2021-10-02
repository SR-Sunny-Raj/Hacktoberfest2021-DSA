"""

Problem Name: Bench Press
CodeChef Link: https://www.codechef.com/LTIME95C/problems/BENCHP/
Problem Code: BENCHP

"""

import collections as c 
for i in range(int(input())):
    n, w, wr = map(int, input().split())
    li = list(map(int, input().split()))
    li2 = dict(c.Counter(li))
    pp = 0
    each = 0
    for j in li2:
        if li2[j] > 1:
            if li2[j] % 2 != 0:
                each = li2[j]- 1 
            else:
                each = li2[j]
            pp += (j * each)
        
    if (wr + pp) >= w:
        print("YES")
    else:
        print("NO")
