//reverse a kinked list using recursion
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;


void addLast(int val)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next     = NULL;

    //if head is NULL, it is an empty list
    if(head == NULL)
         head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}
void reverseList(struct node* p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    //calling the function recursively
    reverseList(p->next);
    struct node* q=p->next;
    q->next=p;
    p->next=NULL;
}
void printList()
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
     head = NULL;

     addLast(10);
     addLast(20);
     addLast(30);
     addLast(50);
     addLast(60);
     addLast(70);

     printList();

     reverseList(head);

     printList();

     return 0;
}
