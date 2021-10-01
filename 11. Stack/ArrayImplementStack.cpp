#include <bits/stdc++.h>
using namespace std;

struct Stack {
    
    int *arr;
    int cap;
    int top;
    
    Stack(int c)
    {
        cap=c;
        top=-1;
        arr= new int[cap];
    }
    
    void push(int x)
    {
        if(top==cap-1)
        {
            cout<<"Stack full"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    
    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack empty"<<endl;
            return INT_MIN;
        }
        int res= arr[top];
        top--;
        return res;
    }
    
    int size()
    {
        return top+1;
    }
    
    int peek()
    {
        return arr[top];
    }
    
    bool isempty()
    {
        return top==-1;
    }
    
};

int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    s.push(15);
    cout<<s.size()<<endl;
    cout<<s.isempty();
    
}