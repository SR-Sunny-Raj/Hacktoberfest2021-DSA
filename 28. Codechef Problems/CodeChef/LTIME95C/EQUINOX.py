"""

Problem Name: Equinox
CodeChef Link: https://www.codechef.com/LTIME95C/problems/EQUINOX/
Problem Code: EQUINOX

"""

for i in range(int(input())):
    N, A, B = map(int, input().split())
    anu = 0
    sar = 0
    for i in range(N):
        s = input()
        if s[0] in "EQUINOX":
            sar += A 
        else:
            anu += B
    
    if sar == anu:
        print("DRAW")
    elif sar > anu:
        print("SARTHAK")
    else:
        print("ANURADHA")
