import math
a = float(input("Enter the first coefficient: "))
b = float(input("Enter the second coefficient: "))
c = float(input("Enter the third coefficient: "))
if (a!=0.0):
    d = (bb)-(4ac) 
    if (d==0.0):
        print("The roots are real and equal.") 
        r = -b/(2a)
        print("The roots are ", r,"and", r)
    elif(d>0.0):
        print("The roots are real and distinct.")
        r1 = (-b+(math.sqrt(d)))/(2a) 
        r2 = (-b-(math.sqrt(d)))/(2a)
        print("The root1 is: ", r1)
        print("The root2 is: ", r2)
    else:
        print("The roots are imaginary.")
        rp = -b/(2a) ip = math.sqrt(-d)/(2a)
        print("The root1 is: ", rp, "+ i",ip)
        print("The root2 is: ", rp, "- i",ip)
else:
    print("Not a quadratic equation.")