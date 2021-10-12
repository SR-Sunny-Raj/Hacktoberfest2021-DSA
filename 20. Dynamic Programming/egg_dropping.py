"""
You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.
What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

"""

def eggDropping(eggs,floors):
    if floors==0 or floors==1:
        return floors
    if eggs==1:
        return floors

    if dp[eggs][floors]!=-1:
        return dp[eggs][floors]
    
    minimum=float("inf")
    temp=0

    #check for all floors
    for k in range(1,floors+1):
        #here max is used because we want to find the no of attempts in the WORST CASE
        #so which ever case provides more attempts will be the answer
        temp=1+max(eggDropping(eggs-1,k-1),eggDropping(eggs,floors-k))

        #but out of all the worst cases we have to find the minimum therefore min is used here
        minimum=min(minimum,temp)

    #store the result in dp array
    dp[eggs][floors]=minimum
    return minimum


e=3
f=14

#make a dp array of dimensions "e x f"
dp=[[-1 for _ in range(f+1)]for _ in range(e+1)]

print(eggDropping(e,f))