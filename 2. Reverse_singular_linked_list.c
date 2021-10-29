#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*start;

void create(int );
void reverse();
void print();

int main()
{
    int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("\nThe List is \n");
    print();
    printf("\nThe Reversed Linked List is\n");
    reverse();
    print();
    return 0;
}

void create(int n)
{
    struct node *ptr, *temp;
    int data, i;
    start = (struct node *)malloc(sizeof(struct node));

    if(start == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        printf("\nEnter the value of Start: ");
        scanf("%d", &data);
        start->data = data;
        start->next = NULL;
        temp = start;
        for(i=2; i<=n; i++)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            if(ptr == NULL)
            {
                printf("\nList is empty.\n");
                break;
            }
            else
            {
                printf("\nEnter next element: ");
                scanf("%d", &data);
                ptr->data = data;
                ptr->next = NULL;
                temp->next = ptr;
                temp = temp->next;
            }
        }
    }
}

void reverse()
{
    struct node *ptr = start;
    struct node *prev = NULL, *next = NULL;
    while (ptr != NULL)
    {

        next = ptr->next;

        ptr->next = prev;

        prev = ptr;
        ptr = next;
    }
    start = prev;
}

void print()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr=start;
        while(ptr != NULL)
        {
            printf("\t %d", ptr -> data);
            ptr = ptr -> next;
        }
    }
}
