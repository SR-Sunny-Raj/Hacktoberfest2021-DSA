#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head=0;


//insert at end
void ie(int x)
{
    struct node * newnode=0;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==0)
    {
        printf("\nOverflow");
        return;
    }

    newnode->data=x;
    newnode->next=0;

    if(head==0)
    {
        head=newnode;
    }
    else
    {
        struct node * lastNode = head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newnode;
    }
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
    ie(10);
    print();
    ie(20);
    print();
    ie(30);
    print();

    return ;
}

