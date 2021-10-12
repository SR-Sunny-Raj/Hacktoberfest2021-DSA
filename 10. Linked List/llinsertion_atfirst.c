// C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to Insert at the begining of a node */
struct Node* Insert_at_begin(struct Node* head, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head= new_node;
    return head;
}
 
/* Function to print linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    
    head=Insert_at_begin(head, 20);
    /* List will be 20->NULL*/
    head=Insert_at_begin(head, 4);
    /* List will be 4->20->NULL*/
    head=Insert_at_begin(head, 15);
    /* List will be 15->4->20->NULL*/
    head=Insert_at_begin(head, 85);
    /* List will be 85->15->4->20->NULL*/
 
    printf("Created linked list is\n");
    printList(head);
    
}
