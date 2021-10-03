""" 
fibonacci series is a series of number in which each number is the sum of its previous two numbers

ex:  0, 1, 1, 2, 3, 5, 8....................


"""

def fib(n):
  if(n == 1):
    return 0
  elif(n == 2):
    return 1
  else:
    return fib(n-2)+fib(n-1)

n = int(input("Enter the number of terms you wants to print")
for i in range(n):
        print(fib(i), end = " ")
  
