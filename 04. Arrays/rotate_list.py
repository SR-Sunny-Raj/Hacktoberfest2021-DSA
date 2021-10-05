def rotate(arr, n):
    n = len(arr)
    i = 1
    x = arr[n - 1]
    for i in range(n - 1, 0, -1):
        arr[i] = arr[i - 1]

    arr[0] = x

    return arr

A = [1, 2, 3, 4, 5]
a=rotate(A,5)
print(a)
