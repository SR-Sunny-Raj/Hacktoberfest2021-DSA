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
Node *evenAfterOdd(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *oddHead=NULL, *oddTail=NULL,*evenHead=NULL,*evenTail=NULL;
    while(head!=NULL)
    {
        if(head->data %2==0)
        {
            if(evenHead==NULL)
            {
                evenHead=head;
                evenTail=head;
            }
            else
            {
                evenTail->next=head;
                evenTail=head;
            }
        }
        else
        {
            if(oddHead==NULL)
            {
                oddHead=head;
                oddTail=head;
            }
            else
            {
                oddTail->next=head;
                oddTail=head;
            }
        }
        head=head->next;
    }
    if(oddHead==NULL)
    {
        evenTail->next=NULL;
        return evenHead;
    }
    if(evenHead==NULL)
    {
        oddTail->next=NULL;
        return oddHead;
    }
    oddTail->next=evenHead;
    evenTail->next=NULL;
    return oddHead;
}
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
