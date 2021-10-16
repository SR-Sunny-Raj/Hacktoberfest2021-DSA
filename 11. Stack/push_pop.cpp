#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class stack
{
    private:
    Node *top;

    public:
    stack(){top=NULL;}
    void push(int x);
    int pop();
    void display();
};

void stack::push(int x)
{
    Node *p;
    p=new Node;
    if(p==NULL)cout<<"stack full";
    else
    {
        p->data=x;
        p->next=top;
        top=p;
    }
}

int stack::pop()
{
    int x=-1;
    if(top==NULL)cout<<"stack empty";
    else
    {
        x=top->data;
        Node *p=top;
        top=top->next;
        delete p;
    }
    return x;
}
void stack::display()
{
    Node *p=top;
    cout<<"displaying the stack"<<endl;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(5);
    st.display();
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    st.display();
}