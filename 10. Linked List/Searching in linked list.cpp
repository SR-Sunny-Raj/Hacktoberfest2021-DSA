//Searching in linked list

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
}*head=NULL;

void createll(int arr[],int n,node* head)
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

node *searchlli(node *ptr,int key)
{
    while(ptr!=NULL)
    {
        if(key==ptr->data)
            return (ptr);
            
        ptr=ptr->next;    
    }
    return NULL;
}

node *searchllr(node *ptr,int key)
{
    if(ptr==NULL)
        return NULL;
        
    else
    {
        if(ptr->data==key)
            return ptr;
            
        return searchllr(ptr->next,key);    
    }
}


int main()
{
    int arr[]={14,2,7,4,5};
    
    node *temp, *t;
    
    node *head=new node();
    
    createll(arr,5,head);
    
    int key;
    cin>>key;
    
    temp=searchlli(head,key);
    
    if(temp)
        cout<<"value found";
    
    else
        cout<<"value not found";
    
    searchllr(head,key);
    
    t=searchllr(head,key);
    
    if(t)
        cout<<"\nvalue found recursively";
    
    else
        cout<<"\nvalue not found recursively";
        
    return 0;    
}
