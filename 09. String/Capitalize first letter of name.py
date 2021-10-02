''' Probelem Statement : Write a program to capitalize first letter of your name or any string entered'''
 x=input()
 def solve(s):
   string=s.split(" ")
   return(' '.join((word.capitalize()for word in string))

 
 
  result=solve(x)
 print(result)
