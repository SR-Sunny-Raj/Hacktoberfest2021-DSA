for i in range(int(input())):
    fact=1
    a=int(input())
    for j in range(1,a+1,1):
        fact=fact*j
    print(fact)
    
 def factorial(n):
     
    return 1 if (n==1 or n==0) else n * factorial(n - 1);
 
num = int(input('Enter number'))
print("Factorial of",num,"is",
factorial(num))
