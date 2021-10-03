/*  In this problem we will arrange the elements such that 
    all the even numbers are placed after the odd numbers and 
    The relative order of the odd and even terms should remain unchanged. */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// this function will take input from user
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

// this function will print our desired result

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// our function to do the desired work

Node *evenAfterOdd(Node *head)
{
    Node *temp = head;
    Node *evenHead = NULL;
    Node *oddTail = NULL;
    Node *oddHead = NULL;
    Node *evenTail = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        else if (temp->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        temp = temp->next;
    }
    if (oddHead == NULL)
    {
        head = evenHead;
    }
    else
    {
        oddTail->next = evenHead;
        head = oddHead;
    }
    if (evenTail != NULL)
    {
        evenTail->next = NULL;
    }
    return head;
}

// driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}