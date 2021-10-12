#Sort an array using merge sort

def merge_all(arr, l, m, r):
    #function to merge the accepted array
	n1 = m - l + 1
	n2 = r - m
	L = [0] * (n1) #forming two empty arrays
	R = [0] * (n2)
	for i in range(0, n1): 
		L[i] = arr[l + i]

	for j in range(0, n2):
		R[j] = arr[m + 1 + j]
	i = 0	 
	j = 0	 
	k = l	 

	while i < n1 and j < n2:
		if L[i] <= R[j]:
			arr[k] = L[i]
			i += 1
		else:
			arr[k] = R[j]
			j += 1
		k += 1
	while i < n1:
		arr[k] = L[i]
		i += 1
		k += 1
	while j < n2:
		arr[k] = R[j]
		j += 1
		k += 1


def merge_sort(arr, l, r): #function to perform the merge sort using recursion
	if l < r:
		m = l+(r-l)//2
		merge_sort(arr, l, m) #perform merge sort on 1st half of accepted array
		merge_sort(arr, m+1, r) #perform merge sort on 2nd half of accepted array
		merge_all(arr, l, m, r) #combining both the halves of the original array

array=[]
n=int(input("Enter length of array: "))
for i in range(0,n): #loop to accept the array
    m=int(input())
    array.append(m)

merge_sort(array, 0, n-1)
print("Sorted array is")
for i in range(n): #loop to print the array
	print(array[i])