#include<bits/stdc++.h>
using namespace std;
  
typedef pair<int, int> A;
class Stack{
    int count;
    priority_queue<pair<int, int> > pq;
public:
    Stack():count(0){}
    void push(int n);
    void pop();
    int top();
    bool isEmpty();
};
  
                                                                                      // returns the top element in the stack
int Stack::top(){
    A temp=pq.top();
    return temp.second;
}
                                                                                       //push element and increase count  
void Stack::push(int n){
    count++;
    pq.push(A(count, n));
}
  
                                                                                      // pops element and reduces count
void Stack::pop(){
    if(pq.empty()){ cout<<"Nothing to pop!!!";}
    count--;
    pq.pop();
}

                                                                                      // check if stack is empty
bool Stack::isEmpty(){
    return pq.empty();
}
 
int main()
{
    Stack* s=new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    while(!s->isEmpty()){
        cout<<s->top()<<endl;
        s->pop();
    }
}
