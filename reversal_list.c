//wap to reverse the elements f linkedlist

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

 int insertbeg(int val)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=head;
    head=ptr;

}
void print()
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
       ptr= ptr->next;
    }
}

void reverse(struct node **head)
{
    struct node *left=NULL;
    struct node *right;
    struct node *current=*head;
    while(current!=NULL)
    {
        right=current->next;
        current->next=left;
        left=current;
        current=right;


    }
    *head=left;
}

void main()
{
    insertbeg(8);
    insertbeg(3);
    insertbeg(5);
    insertbeg(2);
    print();
    printf("\n");
    reverse(&head);
    printf("linkedlist after reversal\n");
    print();

}
output:
2 5 3 8
linkedlist after reversal
8 3 5 2

© 2021 GitHub, Inc.
Term
