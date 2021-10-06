#include<bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};

void insert(Node **head, int data){

    Node *tmp = new Node(data);
    
    tmp->next=tmp->prev=NULL;

    if(!(*head)){
        (*head)=tmp;
    }
    else {
        tmp->next= *head;
        (*head)->prev=tmp;
        (*head)=tmp;
    }

}

void push(Node **head, int data){

    Node *new_Node = new Node(data);
    
    new_Node->prev=NULL;
    new_Node->next=(*head);

    if((*head)!=NULL)
        (*head)->prev=new_Node;
    
    (*head)=new_Node;

}

void printList(Node *head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void pairSum(struct Node *head, int x)
{
    struct Node *first = head;
    struct Node *second = head;
    while (second->next != NULL)
        second = second->next;


        bool found = false;

    while (first != second && second->next != first)
    {
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", "
                << second->data << ")" << endl;

            first = first->next;

            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }

    if (found == false)
        cout << "No pair found";
}


int main(){

    Node *head = NULL;

    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;

    cout<<"Original Linked list = ";
    printList(head);

    pairSum(head, x);

    return 0;
}
