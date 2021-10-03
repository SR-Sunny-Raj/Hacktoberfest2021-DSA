//Implementation Of Circular Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct cnode
{
    int data;
    struct cnode * next;
}Node;

typedef struct
{
    Node * last;
}CLL;

void insertbeg(CLL * lptr, int ele)
{
    Node * p;
    p = (Node * ) malloc(sizeof(Node));
    p -> data = ele;

    if (lptr -> last == NULL)
    {
        lptr -> last = p;
        p -> next = lptr -> last;
    }
    else
    {
        p -> data = ele;
        p -> next = lptr -> last -> next;
        lptr -> last -> next = p;
    }

}

void insertend(CLL * lptr, int ele) //insert node at end
{
    Node * p;
    p = (Node * ) malloc(sizeof(Node));
    p -> data = ele;

    if (lptr -> last == NULL) //is this a first node?
    {
        lptr -> last = p; //start points to p
    }
    else
    {
        if (lptr -> last != NULL)
        {
            p -> next = lptr -> last -> next;
            lptr -> last -> next = p;
            lptr -> last = p;
        }
    }
}

void deletenode(CLL * lptr, int x)
{
    Node * q = lptr -> last -> next; //q points to first node
    Node * prev = lptr -> last; //previous of first node is the last node
    int flag = 1; //false = 1 and true =0

    if (lptr -> last == NULL)
    {
        printf(" No Nodes in the Circular linked list\n");
        return;
    }
    do
    {
        if (q -> data == x)
        {
            flag = 0; //if data found set the flag
            break;
        }
        else
        {
            prev = q; //advance prev
            q = q -> next; //Advance q
        }
    }while (q != lptr -> last -> next);

    if (flag == 1)
    {
        printf(" Data not found");
        return;
    }
    else//if ( flag == true) i.e if data found
    {
        if (q == lptr -> last -> next)
        {//if first node gets deleted
            lptr -> last -> next = q -> next;
        }
        else if (q == lptr -> last)
        { //for last node
            lptr -> last = prev ;
            prev -> next = q -> next;
        }
        else
        {//for middle node
            prev -> next = q -> next;
        }
        free(q);
    }
}

void display(CLL l)
{
      Node * q;
      q = l.last -> next; //begin with first node
      while (q != NULL && q != l.last)
      {//until u reach last node
            printf(" %d\t", q -> data);
            q = q -> next;
      }
      printf(" %d\t", q -> data);

}

int countnodes(CLL l)
{
    int count = 0;

    Node * q;
    q = l.last -> next; //begin with first node
    while (q != l.last)
    {//until u reach last node
        count++;
        q = q -> next;
    }
    return count + 1;
}

int main()
{

      CLL l1; //three linked list of integers
      l1.last = NULL;

      int choice, ele;
      printf("===================================================================================================\n");
      printf("\n Menu :\n 1.Insert at beg \n 2.Insert at end\n 3.Delete Data\n 4.Display\n 5.Count Nodes\n 6.Exit\n\n");
      printf("===================================================================================================\n");
      do
      {
            printf("\n Enter your choice : ");
            scanf("%d", & choice);
            printf("\n");
            switch (choice)
            {
                case 1:
                  printf(" Enter the element to be added at the beginning of the Linked List : ");
                  scanf("%d", & ele);
                  insertbeg( & l1, ele);
                  break;

                case 2:
                  printf(" Enter the element to be added at the end of the Linked List : ");
                  scanf("%d", & ele);
                  insertend( & l1, ele);
                  break;

                case 3:
                  printf(" Enter the data to be deleted : ");
                  scanf("%d", & ele);
                  deletenode( & l1, ele);
                  break;

                case 4:
                  printf(" The Linked List is :\n");
                  display(l1);
                  printf("\n");
                  break;

                case 5:
                  printf(" The total nodes in the Linked List are : %d\n", countnodes(l1));
                  break;

                case 6:
                  exit(0);
            }

      }while (1);

      return 0;
}
/*************************************************************************************************
OUTPUT :
===================================================================================================

 Menu :
 1.Insert at beg
 2.Insert at end
 3.Delete Data
 4.Display
 5.Count Nodes
 6.Exit

===================================================================================================

 Enter your choice : 1

 Enter the element to be added at the beginning of the Linked List : 20

 Enter your choice : 1

 Enter the element to be added at the beginning of the Linked List : 10

 Enter your choice : 2

 Enter the element to be added at the end of the Linked List : 30

 Enter your choice : 2

 Enter the element to be added at the end of the Linked List : 40

 Enter your choice : 4

 The Linked List is :
 10      20      30      40

 Enter your choice : 3

 Enter the data to be deleted : 40

 Enter your choice : 3

 Enter the data to be deleted : 10

 Enter your choice : 4

 The Linked List is :
 20      30

 Enter your choice : 5

 The total nodes in the Linked List are : 2

 Enter your choice : 6


Process returned 0
*************************************************************************************************/
