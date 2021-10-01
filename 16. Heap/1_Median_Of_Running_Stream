/* Median Of Running Stream */
/*
    Median is the middle value (or average of middle values) of a series 
    when arranged in sorted order.

    Given a stream of number, it is required to print median of running stream,
    That is, If there are n numbers in streams print n medians M1, M2 ... Mn
    Mi = median( num_1, num_2, ... , num_i )

    For Example:
    Let Stream = 1, 4, 2
    Medians =    1, 2.5, 2

    Explanation: 
    M1 = median(1) = 1
    M2 = median(1, 4) = (1+4)/2  = 2.5
    M3 = median(1, 4, 2) = median(1, 2, 4) = 2   // sorted order

    Approach:
    Brute force is to keep on adding number to array and sorting it everytime
    and get middle or average of middle values.

    Efficient approach is to maintain two heaps - one mean heap and other max heap
    for a sorted array, put greater half in minHeap and smaller half on maxHeap.
    If size of heaps are same then median is average of top elements of both heaps
    else the one which has higher size has median as top elements.

    While making heap from running stream, ensure at everypoint of time
    | size(min Heap) - size( max Heap) | <= 1

*/


#include<bits/stdc++.h>

using namespace std;

priority_queue<int> maxQ;   // maxHeap
priority_queue<int, vector<int>, greater<int>> minQ;    //minHeap
double med = INT_MIN;

void printMedian(int num) {

    // putting number on basis of previous median
    if(num > med) 
        minQ.push(num);
    else maxQ.push(num);

    // shifting in case of one heap size have two more values
    // than other heap
    if((int)maxQ.size() - (int)minQ.size() > 1 )
    {
        minQ.push(maxQ.top());
        maxQ.pop();
    }
    else if((int)minQ.size() - (int)maxQ.size() > 1)
    {
        maxQ.push(minQ.top());
        minQ.pop();
    }

    // finding median
    if(maxQ.size() == minQ.size())
        med = (double)(maxQ.top()+minQ.top())/2.0;

    else if(maxQ.size() > minQ.size())
        med = maxQ.top();

    else if(maxQ.size() < minQ.size())
        med = minQ.top();

    //printing median
    cout<<med<<" ";
}

int main()
{
    int n = 6;
    int streams[n] = {1, 4, 2, 3, 5, 6};
    for(int i=0;i<6;i++)
    {
        printMedian(streams[i]);
    }
}
