def mergeSort(nlist,count):
    print("Splitting ",nlist)
   # count=0
    if len(nlist)>1:
        mid = len(nlist)//2
        lefthalf = nlist[:mid]
        righthalf = nlist[mid:]

        count+=mergeSort(lefthalf,count)
        count+=mergeSort(righthalf,count)
        i=j=k=0       
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                nlist[k]=lefthalf[i]
                i=i+1
            else:
                nlist[k]=righthalf[j]
                count+=mid-i
                j=j+1
            k=k+1

        while i < len(lefthalf):
            nlist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            nlist[k]=righthalf[j]
            j=j+1
            k=k+1
    return count
arr=[]
count=0
print("Enter number of elements:-")
n=int(input())
for i in range(0,n):
    x=int(input())
    arr.append(x)
print("elements are:")
print(arr)
print("Total Number of inversions are" ) 
print(mergeSort(arr,count))
#Example
#Enter number of elements:-
#5
#10
#12
#9
#7
#8
#elements are:
#[10, 12, 9, 7, 8]
#Total Number of inversions are
#('Splitting ', [10, 12, 9, 7, 8])
#('Splitting ', [10, 12])
#('Splitting ', [10])
#('Splitting ', [12])
#('Splitting ', [9, 7, 8])
#('Splitting ', [9])
#('Splitting ', [7, 8])
#('Splitting ', [7])
#('Splitting ', [8])
#8
