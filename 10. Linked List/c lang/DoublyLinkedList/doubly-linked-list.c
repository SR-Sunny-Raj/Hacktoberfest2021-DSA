#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node*next;
	struct node*prev;
};
struct node*header=NULL;
struct node*last=NULL;
void create();
void display();
void insert();
void delete1();
//void alter();
void deletelast();
void deletepart();
void displayreverse();
int main()
{
	int ch=20;
	do
	{
		printf("press 1 to create a list\n");
		printf("press 2 to insert a number\n");
		printf("press 3 to display a list \n");
		printf("press 4 to deleting 1 element of a list item\n");
		printf("press 5 to deleting last element of a list item\n");
		printf("press 6 to delete particular element of a list item\n");
		printf("press 7 to display reverse of a list \n");
		printf ("press 8 to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("create\n");
					create();
					break;
			case 2: printf("insert\n");
					insert();
					break;
			case 3: printf("display\n");
					display();
					break;
			case 4: printf("delete first\n");
					delete1();
					break;
			case 5: printf("delete last\n");
					deletelast();
					break;
			case 6: printf("delete particular\n");
					deletepart();
					break;
			case 7: printf("display reverse\n");
					displayreverse();
					break;
			case 8: printf("alternate\n");
				//	alter();
					break;
			case 9: printf("::::::::::::EXIT:::::::::::\n");
					break;
			default:printf("invalid input");
		}
	}
	while(ch!=10);
}
void create()
{
	int i,n;
	struct node*t1=NULL;
	printf("enter the number of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		t1=(struct node*)malloc(sizeof(struct node));
		printf("enter the integer part");
		scanf("%d",&t1->a);
		t1->next=NULL;
		t1->prev=NULL;
		if(header==NULL)
		{
			header=last=t1;
		}
		else
		{
			last->next=t1;
			t1->prev=last;
			last=t1;
		}
	}
}
void display()
{
	struct node*temp=NULL;
	temp=header;
	while(temp!=NULL)
	{
		printf("->%d\n",temp->a);
		temp=temp->next;
	}
}
void delete1()
{
	struct node*temp;
	temp=header;
	if(header==NULL)
	{
		printf("detletion not possible");
		return;
	}
	if(header->next==NULL)
	{
		header=NULL;
	}
	header=header->next;
	header->prev=NULL;
}
void deletelast()
{
	struct node*temp;
	if(header==NULL)
	{
		printf("detletion not possible");
		return;
	}
	if(header->next==NULL)
	{
		header=NULL;
	}
	last->prev->next=NULL;
}
void deletepart()
{
	struct node*temp;int i;
	printf("enter the int part to be deleted");
	scanf("%d",&i);
	temp=header;
	if(header->a==i)
	{
		header=header->next;
	}
	else
	{
	while(temp->a!=i)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	}
	printf("element is not present");
}
void insert()
{
	struct node *temp,*newnode ;int  k,q;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the integer to be inserted\n");
	scanf("%d",&newnode->a);
	printf("\nthe integer before which it is to be inserted\n");
	scanf("%d",&q);
	temp=header;
	while(temp->a!=q)
	{
		temp=temp->next;
	}
	temp->prev->next=newnode;
	newnode->next=temp;
	newnode->prev=temp->prev;
	temp->prev=newnode;
}
void displayreverse()
{
	struct node*temp=NULL;
	temp=last;
	while(temp!=NULL)
	{
		printf("->%d\n",temp->a);
		temp=temp->prev;
	}
}
void inserlast()
{
	struct node*temp,*last2;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the integer part");
	scanf("%d",temp->a);
	if(header==NULL)
	{
		header=last2=temp;
		temp->next=NULL;
		temp->prev=NULL;
		return;
	}
	else
	{
		last2->next=temp;
		temp->next=NULL;
		temp->prev=last2;
		last2=temp;
	}
	temp->next=NULL;
	temp->prev=NULL;
	last->next=temp;
	temp->prev=last;
}
/*void alter()
{
	struct node*temp;
	temp=header;
	while(temp!=NULL || temp->next!=NULL)
	{
		printf("%d",temp->a);
		temp=temp->next->next;
	}
}*/
/*}
void reverse()
{
	struct node *temp,*prev,*next;
	temp=header;
	while(temp!=NULL)
	{
		if(header==temp)
		{
			next=temp->next;
			tem
}
*/
