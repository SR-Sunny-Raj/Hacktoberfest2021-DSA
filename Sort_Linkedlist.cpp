
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    if(head==NULL)
    cout<<"NULL";
    else{
        cout<<head->data<<" ";
        display(head->next);
    }
}



void sort(struct node *head)
{
    struct node *t1,*t2;
    int k;
    t1=head;
    
    while(t1!=NULL)
    {
        for(t2=t1->next;t2!=NULL;t2=t2->next)
        {
            if(t1->data > t2->data)
            {
                k=t1->data;
                t1->data=t2->data;
                t2->data=k;
            }
        }
        t1=t1->next;
    }
    
    cout<<endl;
    display(head);
}



int main()
{
    int i,n;
    struct node *head,*prev,*p;
    cout<<"size of ll:";
    cin>>n;
    head=NULL;
    for(i=0;i<n;i++)
    {
        p=(node*)malloc(sizeof(node));
        cin>>p->data;
        if(head==NULL)
        head=p;
        else
        prev->next=p;
        prev=p;
    }
    display(head);
    sort(head);
   
  
 
return 0;
}

