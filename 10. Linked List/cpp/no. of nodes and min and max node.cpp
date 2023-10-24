#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
node *temp, *head, *newnode;
void *Insert( int x)
{
    newnode= new node(x);
    if(head==NULL)
    {
        temp=head=newnode;
    }

    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}
void displayAndCount()
{

    int m=temp->data; int n=temp->data;
    int c=0;
    temp=head;
    cout<<"The list is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(m<temp->data)
        {
            m=temp->data;
        }
        if(n>temp->data)
        {
            n=temp->data;
        }
        c++;
        temp=temp->next;

    }
    cout<<"\nNo. of nodes: "<<c<<"\nMin value: "<<n<<"\nMax value: "<<m;
}
int main()
{
    head=NULL;
    string a="y"; int i;
    while(a=="y")
    {
        cout<<"enter the element:";
        cin>>i;
        Insert(i);
        cout<<"do you want to enter more?(y/n)";
        cin>>a;
    }
    displayAndCount();
    return 0;
}
