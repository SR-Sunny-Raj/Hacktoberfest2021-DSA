/*GFG Problem
Problem Statement
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.*/

queue<int> modifyQueue(queue<int> q, int k) {
    
    int n = q.size();
    stack<int> s;
   
   for (int i=0; i<k; i++){ // store k queue elements in stack to reverse them
       int temp = q.front();
       q.pop();
       s.push(temp);
   }
   
   for (int i=0; i<k; i++){// push reversed elements back to queue
       int tmp = s.top();
       s.pop();
       q.push(tmp);
   }
   
   for (int i=0; i<n-k; i++){// push remaining elements in same order
       q.push(q.front());
       q.pop();
   }
   
   return q;
}