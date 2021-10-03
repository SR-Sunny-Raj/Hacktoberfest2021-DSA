
//Problem - Insert node at iTH position in a linked list
/*By Pratyaksh Khurana*/

#include<bits/stdc++.h>
using namespace std;

 //class node for implementing linked list
class node 
{
public:

    //value that the node contains
    int data;

    //address of the next node
    node *next;

    //constructor to initialising node
    node(int data)
    {
        this->data = data;
        next = NULL;
    }    
};


//Taking input in a linked list until user enters -1
node* input()
{
    int data;
    cin>>data;
    
    node *head = NULL;
    node *tail = NULL;

    while(data != -1)
    {
        node *newnode = new node(data);
        
        if(head == NULL)
        {
          head = newnode;
          tail = newnode;
        }
        else 
        {
            tail->next = newnode;
            tail = newnode;
        }  
        cin>>data;
    }
   return head;
}

//printing the linked list
void print(node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

}

//insert node at a specific position by the user 
node* insertNode(node *head,int i,int data)
{
     //create new node;
    node *insert_node = new node(data);

   int idx = 0;
   node *temp = head; 
   
   //edge case
   if( i == 0) 
   {
       insert_node->next = head;
       head = insert_node;
       return head;

   }
   
   while(temp != NULL && idx < i-1)
   {
       temp = temp->next;
       idx++;
   }
   
    //edge case
   if(temp != NULL)
   {
     insert_node->next = temp->next;
     temp->next = insert_node;
   }   
   return head;

}

int main()
{
 
    //input linked list 
    node *head = input(); 
    cout<<"Before insertion : ";
    //print linked list
    print(head);         
    
    int i,d;
    cin>>i>>d; 

    /*as we r passing address of first node 
     so no need to return as changes will
     reflect as we pass by reference
    */ 

    head = insertNode(head,i,d); 
    cout<<endl<<"After insertion : ";

    print(head);     

    return 0;
}
