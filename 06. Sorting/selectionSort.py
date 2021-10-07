#Define array
array = [64, 25, 12, 22, 11]
 
# Loop through all array elements
for i in range(len(array)):
     
    # Find the minimum item first
    min_index = i
    for j in range(i+1, len(array)):
        if array[min_index] > array[j]:
            min_index = j
             
    # Swap the min with first element     
    array[i], array[min_index] = array[min_index], array[i]
 
#print the sorted array
print ("Sorted array")
for i in range(len(array)):
    print("%d" %array[i]),