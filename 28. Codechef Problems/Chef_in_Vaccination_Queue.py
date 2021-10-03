# CODECHEF STARTERS 13 DIVISION2 - PROBLEM STATEMENT
#----------------------------------------------------------------------------------------------------------------------
# There are N people in the vaccination queue, Chef is standing on the Pth position from the front of the queue.
# It takes X minutes to vaccinate a child and Y minutes to vaccinate an elderly person. Assume Chef is an elderly person.

# You are given a binary array A1,A2,…,AN of length N, where Ai=1 denotes there is an elderly person standing 
# on the ith position of the queue, Ai=0 denotes there is a child standing on the ith position of the queue. 
# You are also given the three integers P,X,Y. Find the number of minutes after which Chef's vaccination will be completed.


# ---------------------------------------------------------------------------------------------------------------------
# SOLUTION
testcase = int(input())
for _ in range(testcase):
    count0=0 
    count1=0
    n,p,x,y = map(int,input().split())
    array = list(map(int,input().split()))
    for i in range(p):
        if array[i]==0:
            count0+=1
        if array[i]==1:
            count1+=1 
    print((count0*x) + (count1*y))
