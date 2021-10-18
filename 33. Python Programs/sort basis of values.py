n=int(input("Enter n: "))
d={}
while(n):
    key=input("Enter key: ")
    val=input("Enter value: ")
    d[key]=val
    n-=1
#sorting algo
key_list=list(d.keys())
value_list=list(d.values())
i=0
while(i<len(key_list)-1):
    j=0
    while(j<len(key_list)-1):
        if(value_list[j]>value_list[j+1]):
            key_list[j],key_list[j+1]=key_list[j+1],key_list[j]
            value_list[j],value_list[j+1]=value_list[j+1],value_list[j]
        j+=1
    i+=1
toret={key_list[i]:value_list[i] for i in range(0,len(key_list))}
print(toret)
