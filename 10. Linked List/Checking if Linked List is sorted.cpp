//Checking if Linked List is sorted

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

};
node *head=NULL;

void create(int arr[],int n)
{
    int i;
    node *t,*last;
    
    
    
    head->data=arr[0];
    head->next=NULL;
    
    last=head;
    
    for(i=1;i<n;i++)
    {
        node *t=new node();
        t->data=arr[i];
        t->next=NULL;
        
        last->next=t;
        last=t;
    }
}

int sortl()
{
    int x=INT_MIN;
    node *p=head;
    
    while(p)
    {
        if(p->data<x)
            return 0;
        
        x=p->data;
        p=p->next;
    }
    return 1;
}

void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}


int main()
{
    int arr[]={10,20,30,40,50};
    
    head=new node();
   
    create(arr,5);
    
    int x=sortl();
    
    if(x)
        cout<<"Link list is sorted";
    
    else
        cout<<"linked list is unsorted";
    
    return 0;
}
