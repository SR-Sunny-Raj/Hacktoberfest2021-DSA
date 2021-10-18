#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next, *prev;
};
void pairSum(struct Node *head,int x)
{
	int count=0;
	struct Node *front=head;
	struct Node *back=head;
	while(back->next!=NULL)
	back=back->next;
	
	while(front!=back && front && back && back->next!=front)
	{
		if((front->data+back->data)==x)
		{
		count++;
		cout<<'('<<front->data<<','<<back->data<<')'<<endl;
		front=front->next;
		back=back->prev;
		}
		else if((back->data+front->data)>x)
		{
			back=back->prev;
		}
		else
		front=front->next;
	}
	printf("%d",count);
}
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
 
    pairSum(head, x);
 
    return 0;
}
