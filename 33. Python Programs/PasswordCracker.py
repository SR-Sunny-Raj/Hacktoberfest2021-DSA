"""
This program help in crackin a random passsword created , 
it will tell the time taken to crack the password
"""
#importing all the modules needed
import time #time module to calculate time taken to crack the password
import random #random module to create a random password
import string
lower=string.ascii_lowercase #inluding lower letters
upper=string.ascii_uppercase #including capital letters
symbol=string.punctuation #including symbols
num=string.digits #inluding numbers
all = lower+upper+num
temp=random.sample(all,8)
password="".join(temp)
print(f"Your password is = {password}")
begin = time.time()
for i in all:
    if i==password[0]:
        print(f"1st digit: {i} ")
        for j in all:
            if j==password[1]:
                print(f"2nd digit: {j} ")
                for k in all:
                    if k==password[2]:
                        print(f"3rd digit: {k} ")
                        for l in all:
                            if l==password[3]:
                                print(f"4th digit: {l} ")
                                for m in all:
                                    if m==password[4]:
                                        print(f"5th digit: {m} ")
                                        for n in all:
                                            if n==password[5]:
                                                print(f"6th digit: {n} ")
                                                for o in all:
                                                    if o==password[6]:
                                                        print(f"7th digit: {o} ")
                                                        for p in all:
                                                            if p==password[7]:
                                                                print(f"8th digit: {p} ")
                                                                x=i+j+k+l+m+n+o+p
                                                                print(f"Hacked!!! your password is {x} ")
                                                                time.sleep(1)
                                                                end = time.time()                                
                                                                print(f"Time taken to crack the code {end - begin} seconds")
                                                                break
"""
Hope you find this code useful, thankyou.
"""    
                       
