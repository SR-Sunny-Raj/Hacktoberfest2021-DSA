Queries in an Array
Chef has an array A consisting of positive integers. This array is sorted in non-decreasing order from left to right.
You are given Q queries. Each query consists of three integers l, r, x. Answer of this query can be found as follows. Consider the sub array al, al+1… ar. The answer to the query is the count of numbers in this sub array that are greater or equal to x.
Input
•	The first line of each test case contains two space-separated integers n, Q.
•	The second line contains n space separated integers denoting the array A.
•	Each of the next Q lines contains three space-separated integers l, r, x denoting the query.
Output
Output Q lines one for each query containing the answer for the corresponding the query.
Constraints
•	1 ≤ n,Q ≤ 10^5 
•	1 ≤ ai ≤ 10^9
•	1≤ l ≤ r ≤n
•	1 ≤x ≤ 10^9
Sample Input
5 6
1 2 3 6 9
1 5 1
1 5 3
1 5 10
1 4 4
2 5 4
2 5 1
Sample Output
5
3
0
1
2
4
Explanation
•	For the first query, all the elements of the array are ≥1. Thus, the answer is 5.
•	For the second query, the answer will be 3, as the elements 3, 6, 9 are ≥3.


