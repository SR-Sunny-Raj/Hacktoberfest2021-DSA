
//C++ program to detect loop in linkedlist using floyd's cycle finding algorithm
//Linked List skeleton taken from gfg
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
int detectLoop(Node* head)
{
    Node *fast_pointer = head;
    Node *slow_pointer = head;


  /*
    Check for null value for fast_pointer and fast_pointer->next
    So to avoid segmentation fault error for case in which there
    is no loop for both even and odd number of elements
  */
  while(fast_pointer && fast_pointer->next)
  {
    slow_pointer = slow_pointer->next;
    fast_pointer = fast_pointer->next->next;
    if(fast_pointer == slow_pointer)
    {
      return 1;
    }
  }

  return 0;
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}
