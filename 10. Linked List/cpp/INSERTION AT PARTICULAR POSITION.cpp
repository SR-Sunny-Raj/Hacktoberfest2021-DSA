#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};
 

int size = 0;
 

Node* getNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 

// FUNCTION TO INSERT AT PARTICULAR POSITION
void insert_at_particular_postion(Node** current, int pos, int data)
{
    
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
 
        while (pos--) {
 
            if (pos == 0) {
                Node* temp = getNode(data);
                temp->next = *current;
                *current = temp;
            }
            else
              current = &(*current)->next;
        }
        size++;
    }
}
 

// FUNCTION TO PRINT
void print(struct Node* head)
{
    while (head != NULL) {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}
 

// MAIN FUNCTION
int main()
{
    // Creating the list 1->2->3->4
    Node* head = NULL;
    head = getNode(1);
    head->next = getNode(2);
    head->next->next = getNode(3);
    head->next->next->next = getNode(4);
 
    size = 4;
 
    cout << "Linked list before insertion: ";
    print(head);
 
 
    //DATA: TO GET DATA OF NODE TO BE INSERTED
    //POS: TO GET POSITION AT WHICH IT SHOULD BE INSERTED
    
    cout<<"ENTER DATA AND POSITION: ";
    int data, pos;
    cin>>data>>pos;
    
    insert_at_particular_postion(&head, pos, data);
    cout << "Linked list after insertion of "<< data<<"at position "<<pos<<": ";
    print(head);
 
   
    return 0;
}
