def quicksort(arr,sta,end):
    l=end-sta
    #base case not needed as min length =1
    #swapping
    pivot=end-1
    r_ind=sta
    for i in range(sta,end):
        #replacing pivot with r_ind(last swap)
        if i==end-1:
            arr[end-1],arr[r_ind]=arr[r_ind],arr[end-1]
            continue
        #normal swap
        if arr[i]>arr[pivot]:
            continue
        if arr[i]<arr[pivot]:
            arr[r_ind],arr[i]=arr[i],arr[r_ind]
            r_ind+=1
    #sorting r and l
    if r_ind-sta>1:
        quicksort(arr,sta,r_ind)
    if end-r_ind>1:
        quicksort(arr,r_ind,end)
    return arr

        
n=int(input())
ar=list(map(int,input().split(" ")))
result=quicksort(ar,0,len(ar))
print(*result)
