# Binary Search: Search a sorted array by repeatedly dividing the search interval in half. 
# Begin with an interval covering the whole array. 
# If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. 
# Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.

# Enter the sorted list
n = list(map(int, input("Enter List ").split()))

# Enter Element to be Searched
a = int(input("Enter Element to be Searched "))

# Defining a function that can perform task accordingly to given variables
def binary_search(n, a):
  
    # Variable Assigning to perform Binary Search
    low = 0
    mid = 0
    high = len(n)-1
    
    # For loop can be used but we don't know the number of occurances, So, using while loops
    while low <= high:
        mid = (high + low)//2
        if n[mid] < a:
            low = mid + 1
        elif n[mid] > a:
            high = mid - 1
        else:
            return mid
    return "Element is Not Found" 
  
# Calling Function
search = binary_search(n, a)

# Conditional Statements
if search == "Element is Not Found":
    print("Element is Not Present")
else:
    print("Element is Present at index", str(search))
