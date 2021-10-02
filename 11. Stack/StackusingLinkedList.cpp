#include <bits/stdc++.h>
using namespace std;
 
typedef struct Node
{
    int data;
    struct Node* next;
} node;
 
node* top;

void push(int num)
{
    node* temp;
    temp=new Node();
    temp->data=num;
    temp->next=top;
    top=temp;
}

void pop()
{
    node* temp;
    if (top==NULL){
        cout<<"Stack Underflow\n";
        return;
    }
    else{
        temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
}

void display()
{
    node* temp;
    if (top==NULL){
        cout<<"No element in Stack\n";
        return;
    }
    else{
        temp=top;
        while (temp!=NULL){
            if(temp->next!=NULL){
                cout<<temp->data<<"-> ";
                temp=temp->next;
            }
            else{
                cout<<temp->data;
                temp=temp->next;
            }
        }
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    cout<<"\n";
    pop();
    pop();
    push(50);
    push(60);
    push(70);
    pop();
    push(80);
    display();
    cout<<"\n";
          
    return 0;
}
