#    SMALLEST NATURAL NUMBER THAT CANNOT BE REPRESENTED AS SUM IN AN ARRAY

#    1.  Assuming 'res = 1' to be the first and the smallest unreachable number,
#        constantly add the upcoming elements in the sorted array to res until
#        the current array element is smaller than or equal to the value of res.
#        (Since that value CAN be represented as a sum of array elements)

#    2.  Once we get an array element greater than res, that is the required
#        answer. (As it could not be represented as a sum)


def smallest_number(array, n):

    # Sort the array in non-decreasing order
    array.sort()

    # Initialise the res variable
    res = 1

    # Traverse the array and increment 'res' if array[i] is smaller than or equal to 'res'
    for i in range (0, n ):
        if array[i] <= res:
            res = res + array[i]
        else:
            break

    return res

array = [5,6,1,3,8,1,4]
res = smallest_number(array, len(array))
print(res)
