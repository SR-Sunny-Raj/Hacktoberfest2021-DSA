// C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to reverse the linked list */
struct Node* reverse(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
 
/* Function to Insert a node */
struct Node* Insert(struct Node* head, int new_data)
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
 
    head=Insert(head, 20);
    head=Insert(head, 4);
    head=Insert(head, 15);
    head=Insert(head, 85);
 
    printf("Given linked list\n");
    printList(head);
    head=reverse(head);
    printf("\nReversed Linked list \n");
    printList(head);
    
}
