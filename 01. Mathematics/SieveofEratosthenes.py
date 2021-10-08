# The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so.

n = int(input("Enter the Number"))

# Creating a empty array where we store all numbers from 2 to n.
l = [] 

# Creating a empty array where we store number taken out by process.
k = [] 

# Creating a empty array where we store all prime numbers.
m = []

# We create a list of all numbers from 2 to n. 

for i in range(2,n):
    l.append(i)

# According to the algorithm we will mark all the numbers which are divisible by 2.
# Now we move to our next unmarked number 3 and mark all the numbers which are multiples of 3.
# We continue this process

for i in range(2,n):
    for j in range(2,n):
        if i%j==0:
            k.append(i)
        else:
            pass
# Then count the number's which are appearing only one time.

for i in k:
    if k.count(i)==1:
        m.append(i)
    else:
        pass 

# Now printing the prime numbers.      
      
for i in m:
    print(i,end=" ")
    
# Thank you
