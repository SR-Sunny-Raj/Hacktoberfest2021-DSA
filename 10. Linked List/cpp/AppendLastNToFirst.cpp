//AppendLastNToFirst
#include <bits/stdc++.h>
using namespace std;
// Linked List Node class :
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
/********************** Input fun: *********/
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *New = new Node(data);
        if (head == NULL)
        {
            head = New;
            tail = New;
        }
        else
        {
            tail->next = New;
            tail = New;
        }
        cin >> data;
    }
    return head;
}

Node *append_LinkedList(Node *head, int n)
{
    Node *slow = head, *fast = head, *ptr = head->next; //important
    while (n > -1)
    {
        n--;
        if (fast == NULL)
        {
            fast = head;
        }
        fast = fast->next;
    }
    while (fast != NULL)
    {
        ptr = fast;
        fast = fast->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    if (fast != NULL)
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = head;
        head = fast;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{

    Node *head = NULL;
    head = input();
    head = append_LinkedList(head, 3);
    print(head);
}