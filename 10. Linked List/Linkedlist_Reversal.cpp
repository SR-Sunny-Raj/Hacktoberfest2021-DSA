//reversing linked list
#include<iostream>

using namespace std;
//Node of linkedlist
struct node
{
    int data;
    node* next;
};

class linkedlist
{
    public:
    node* head;
    linkedlist(){head=NULL;}
//Function for inserting a new node
    void push(int x)
    {
        node* newnode = new node;
        newnode->data = x;
        newnode->next = head;
        head = newnode;
    }
//Function to display the linkedlist
    void print()
    {
        node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
//Reversing linkedlist using 3pointer method
    void reverse()
    {
        node* prev = NULL;
        node* curr = head;
        node* next = head;
        while(next!=NULL)
        {
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

};

int main()
{
    /* Start with the empty list */
    linkedlist ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();


    return 0;
}
