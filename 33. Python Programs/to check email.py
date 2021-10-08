# Email Collector
import re

def line(st):
    email = re.findall(r"[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+\.[a-zA-Z]+",st)
    print(email)
    

ip = int(input('press\n1)PROVIDE AN INPUT STRING\n2)PROVIDE THE TET FILE WITH THE STRING\n'))

if ip==1:
    a = input('ENTER THE STRING HERE:\n')
    line(a)
elif ip == 2:
    with open("string.txt", "r") as f:
        i = f.read()
        line(i)
else:
    print('WRONG INPUT\n')


