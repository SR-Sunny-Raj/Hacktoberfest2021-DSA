n = int(input())

s = str(input())

ss = s.split(" ")
max = 0
for sss in ss:
    ans  = 0 
    for ssss in sss:
        if ssss.isupper():
            ans +=1
    if max < ans:
        max = ans

print(max)
