"""
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 
Example: 
If length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20


"This is exactly same as unbounded knapsack without any variation"
"""

price=[1, 5, 8, 9, 10, 17, 17, 20]
N=8
length=[i for i in range(1,N+1)]

def rodCutting(price,length,N):

    #Mapping from unbounded knapsack is:
    #val => price  and  wt=> length  

    size=len(price)
    #creating dp array of size 'size x N' where size is length of price array and N is length of rod
    dp=[[0 for j in range(N+1)]for i in range(size+1)]
    
    #loop starting from 2nd row to last row
    for i in range(1,size+1):
        #loop from 1st column to last column
        for j in range(N+1):
            #we include the length
            if length[i-1]<=j:
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j])
            #we dont include the length
            else:
                dp[i][j]=dp[i-1][j]
    return dp[size][N]

print("The max value will be: ",rodCutting(price,length,N))
 