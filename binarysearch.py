lst = [1,3,2,4,5,6,9,8,7,10]
lst.sort()
first=0
last=len(lst)-1
mid = (first+last)//2
item = int(input("enter the number to be search"))
found = False
while( first<=last and not found):
    mid = (first + last)//2
    if lst[mid] == item :
         print(f"found at location {mid}")
         found= True
    else:
        if item < lst[mid]:
            last = mid - 1
        else:
            first = mid + 1 
   
if found == False:
    print("Number not found")
