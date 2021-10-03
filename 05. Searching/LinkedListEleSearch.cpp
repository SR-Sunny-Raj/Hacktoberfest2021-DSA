// SEARCHING OF AN ELEMENT IN LINKY BABY
#include <iostream>
using namespace std;

struct node{
    int data;
    node *ptr;
};

struct node *head=NULL;

void insert(int a){
    struct node *temp=new node;
    temp->data=a;
    temp->ptr=head;
    head=temp;
}
void search(int a){    
    node *p=head;
    while(p && p->data!=a){
        p=p->ptr;
    } 
    if(p!=NULL)
        cout<<"Element Found :"<<a<<endl;
    else
        cout<<"Element not Found :"<<a<<endl;
}
int main()
{
    insert(45);
    insert(55);
    insert(65);
    search(55);
    search(25);
}
