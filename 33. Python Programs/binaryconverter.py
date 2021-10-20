#decimal to binary
n=int(input("Enter decimal number-"))#taking input
s=str()
while(n!=1):
  s+=str(n%2)
  n=n//2
s+=str(1)
print(s[::-1])#reversing
