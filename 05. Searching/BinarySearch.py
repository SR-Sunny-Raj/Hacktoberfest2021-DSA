def binary_search(arr,x):
    low=0
    high=len(arr)-1
    mid=0
    while low<=high:
        mid=(high+low)//2
        if arr[mid] < x:
            low=mid+1
        elif arr[mid] >x:
            high=mid-1
        else:
            return mid
    return -1


arr=[]
n=int(input("Enter no. of elements: "))
print("Enter elements(in new line): ")
for i in range(n):
    arr.append(int(input()))
    
arr.sort()

x=int(input("Enter no. to be searched: "))
result=binary_search(arr,x)

if(result==-1):
    print("Element not found in list")
else:
    print("Element found at index",result)
