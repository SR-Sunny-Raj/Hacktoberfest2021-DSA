/* Minimum Cost for Joining Ropes */
/*
    Given a rope that has been broken into N parts,
    The task is to join the rope into 1 rope back.

    Given condition
    Cost of joining two part = sum of length of both parts

    Requirement:
    Minimum Cost to join the ropes

    Examples:
    pieces = [2,3,1,4,5]
    answer = 

    Explanation
    take parts 1 & 2 join it as length 3
    cost = 3

    now new parts = [3,3,4,5]
    take part 3 & 3 and join it as length 6
    cost = 3 + 6 = 9

    now new parts = [6,4,5]
    now take parts 4 & 5, join it as length 9
    cost = 9 + 9 = 18

    new parts = [6,9]
    taking last two parts 6 & 9,
    finally joining this into 1 rope
    cost = 18 + 6 + 9 = 33

    Answer = 33

    Greedy Approach:
    Always take out the two smallest portion,
    Brute Force : Keep on sorting and element and take out first two elements

    Efficient Approach: Use minimum Heap

    push all elements in heap and keep on taking out 2 elements and push back its sum
    until size of heap becomes unity.
    
    Main the cost

*/

#include <bits/stdc++.h>

using namespace std;

int main() 
{  
    int n = 5;  // size of array
    int pieces[n] = {1, 2, 3, 4, 5};
    int minCost = 0;

    // min Heap
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
        pq.push(pieces[i]);

    while(pq.size() != 1)
    {
        // taking out 2 elements - smallest pieces
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();

        // adding their lenght to the cost
        minCost += p1 + p2;

        // pushing back the added length to the heap
        pq.push(p1 + p2);
    }
    // final answer
    cout<<minCost;
    return 0;
}
