//author : Rutuja Bhure (rbb-99)

/*

PROBLEM STATEMENT :
there's a 2D grid of dimensions m x n 
you are at the top left corner 
find in how many ways you can reach the bottom right corner
if you can only move down or right

eg.                     2,3
            /                          \
           1,3                          2,2
        /      \                     /       \
    0,3        1,2              1,2             2,1 
              /   \            /   \          /    \
           0,2     1,1      0,2     1,1     1,1     0,0

i.e there are 3 ways to travel down a 2x3 grid

*/

#include<bits/stdc++.h>

//function uses a naive approach (for smaller values of m,n)
unsigned gridTraveller(unsigned m, unsigned n);

//function uses a dynamic approach - memoization (for larger values of m,n)
static unsigned gridTravelerMemo(unsigned m, unsigned n);

std::string keyConvertedToString(unsigned m, unsigned n);

std::unordered_map<std::string, int> memo;

int main()
{               
    std::cout<<gridTraveller(2,3)<<std::endl;
    std::cout<<gridTravelerMemo(18,18);
    return 0;
}

unsigned gridTraveller(unsigned m, unsigned n)
{
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;
    return gridTraveller(m-1, n) + gridTraveller(m, n-1);
    //              |                       |
    //          turn down               turn right
    //          no.of rows-1           no.of cols-1 
}
//for this naive brute force recursive implementation,
//space complexity -> O(n+m) (height of the tree)
//time complexity -> O(2^(n+m))



std::string keyConvertedToString(unsigned m, unsigned n)
{
    return (std::to_string(m) + ',' + std::to_string(n));
}

static unsigned gridTravelerMemo(unsigned m, unsigned n)
{       
    const std::string key = keyConvertedToString(m,n);
    if (memo.count(key) > 0) 
        return memo.at(key);
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;
    memo[key] = gridTravelerMemo(m-1, n) + gridTravelerMemo(m, n-1);
    return memo.at(key);
} 
//by memoization,
//time complexity -> O(m*n) since there are m*n combinations as 
//m : {0,1,2,3,...,m} and n : {0,1,2,3,...,n} in the tree with nodes m,n
//space complexity -> O(n+m)
