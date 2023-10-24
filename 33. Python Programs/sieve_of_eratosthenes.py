import math

print ("Enter number upto which you want to display prime numbers")
num = int(input())

prime_list = []
for a in range(2,num+1):
    prime_list.append(a)

a = 2
#from 2 to sqrt(number)
while(a <= int(math.sqrt(num))):
    # If a is found in the list, we remove its multiples
    if a in prime_list:
        # b represents multiples of a from 2a
        for b in range(a*2, num+1, a):
            if b in prime_list:
                # Remove multiple if present in the list
                prime_list.remove(b)
    a = a+1

print("The list of prime numbers upto "+str(num)+" is:")
for a in prime_list:
    print (a)
