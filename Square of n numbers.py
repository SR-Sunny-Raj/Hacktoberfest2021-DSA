''' Problem Statement : To find square of given N numbers using Recursion and iterative approach'''

n=int(input("Enter Number : "))
def squareIterative(n):
    for i in range(n,0,-1):
        print(i**2,end=" ")
squareIterative(n)

print()
def squareRecursive(n):
    if n>0:
        print(n**2,end=" ")
        squareRecursive(n-1)

squareRecursive(n)
