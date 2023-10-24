#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head=0;

//insertion at beginning
void ib(int x)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==0)
    {
        printf("\nOverflow");
        return;
    }

    newnode->data=x;
    newnode->next=head;
    head=newnode;
}

//printing the elements
void print()
{
    if(head==0)
    {
        printf("\nUnderflow");
        return;
    }

    struct node *temp = head;
    printf("\n");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main()
{
    ib(10);
    print();
    ib(20);
    print();
    ib(30);
    print();
}

