# Given an arrray of integers
# Function that returns true if there is a triplet (a,b,c) that satisfies a^2 + b^2 = c^2.
def isTriplet(arr, n):
    j = 0
     
    for i in range(n - 2):
        for k in range(j + 1, n):
            for j in range(i + 1, n - 1):
                x = arr[i]**2
                y = arr[j]**2
                z = arr[k]**2
                if (x == y + z or y == x + z or z == x + y):
                    return 1
     
    return 0

array=[]
n=int(input("Enter length of array: "))
for i in range(0,n):
    m=int(input())
    array.append(m)
 
if(isTriplet(array, n)):
    print("Yes")
else:
    print("No")