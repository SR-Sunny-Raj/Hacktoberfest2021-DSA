// inserting sequential data in linked-list using loops

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void print_list()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d-", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{   // first default node 
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 99;
    head->next = NULL;
    // second default node 
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    curr->data = 98;
    curr->next = NULL;
    head->next = curr;

    struct node *ref = head;
     // using loop to insert data in linked-list
    for (int i = 97; i >= 90 ; i--)
    {
        curr = (struct node *)malloc(sizeof(struct node));
        curr->data = i;
        curr->next = NULL;
        // traversing from head until we get next of NULL
        while (ref->next != NULL)
        {
            ref = ref->next;
        }
        ref->next = curr;
    }

    print_list();
}