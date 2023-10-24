
#include <stdio.h>
#include <stdlib.h>
// A linked list node
struct Node
{
  int data;
  struct Node *next;
};
struct Node* Insert_at_end(struct Node *head, int new_data)
{
    /* 1. allocate node using malloc(Dynamic allocation) function*/
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = head;  
 
    /* we put in the data */
    new_node->data  = new_data;
 
    /*This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;
 
    /*If the Linked List is empty, then make the new node as head */
    if (head == NULL)
    {
       head = new_node;
    }
     /*Else traverse till the last node */
    else{
           
        while (last->next != NULL){
            last = last->next;
        }
        /*Change the next of last node */
         last->next = new_node;
        
    }
    return head;
    
}
// This function prints contents of linked list starting from head node
void printList(struct Node *head)
{
    //creating a tempory node to avoid mis-position of head
    struct Node *temp=head;
    
    //Traversing till the end of the linked list
  while (temp != NULL)
  {
     printf(" %d ", temp->data);
     temp = temp->next;
  }
}
 
int main()
{
  /* Start with the empty list */
  struct Node* head = NULL;
 
  // Insert 6.  So Initially the linked list is 6->NULL
  head=Insert_at_end(head, 6);
 
 
  // Insert 4 at the end. So linked list becomes 6->4->NULL
  head=Insert_at_end(head, 4);
  
  // Insert 3 at the end. So linked list becomes 6->4->3->NULL
  head=Insert_at_end(head, 3);
 
  printf("\n Created Linked list is: ");
  printList(head);
 
  return 0;
}

