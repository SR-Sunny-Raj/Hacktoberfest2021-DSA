#include <stdio.h>
#include <stdlib.h>

//----------------------------------------STRUCTURE------------------------------------------------

struct node{
    int data;
    struct node *next;
}*head=NULL,*temp;

//---------------------------------DECLARATION---------------------------------------------------------------------

int create(void);
void display(void);
void insert_begin(void);
void insert_end(void);
void insert_position(void);
int count(void);
void delete_begin(void);
void delete_position(void);
void delete_end(void);
int search_position(void);
void search_value(void);

//-----------------------------------------MAIN FUNCTION-------------------------------------------------------------------------------------

int main()
{
    int ch=0;
    while(ch<13)
    {
        printf("\n _________________ \n CHOOSE: \n 1.CREATE \n 2.SEE LIST \n 3.INSERT AT BEGGINING \n 4.INSERT AT END \n 5.INSERT BY POSITION \n 6.COUNT \n 7.DELETE AT BEGGINNG \n 8.DELETE BY POSITION \n 9.DELETE AT END \n 10.SEARCH BY POSITION \n 11.SEARCH BY VALUE\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d",&ch);

        switch (ch)
        {

            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert_begin();
                    break;
            case 4: insert_end();
                    break;
            case 5: insert_position();
                    break;
            case 6: count();
                    break;
            case 7: delete_begin();
                    break;
            case 8: delete_position();
                    break;
            case 9: delete_end();
                    break;
            case 10: search_position();
                    break;
            case 11: search_value();  
                    break;             
            default: printf("\n Enter a valid choice. \n");
                    break;
           
        }
    }
}

// ------------------------------------------------LIST CREATING-------------------------------------------------------------

int create()
{
    int n;
    printf("Enter size of list:");
    scanf("%d",&n);
    
    if(n==0)
    {
        return 0;
    }
    else
    {
        while(n>0)
        {
            struct node*ptr= (struct node*)malloc(sizeof(struct node));
            printf("Enter the data:");
            scanf("%d",&ptr->data);
            ptr->next=NULL;
            

            if(head==NULL)
            {
                head=temp=ptr;
            }
            else
            {
                temp->next=ptr;
                temp=ptr;
            }
            temp->next=NULL;
            n--;
        }
    }
}

//--------------------------------------------PRINTING-----------------------------------------------------------------------------

void display()
{
    temp=head;
    while(temp!=NULL)
    {
    printf("%d ,",temp->data);
    temp=temp->next;
    }
}

//-------------------------------------------------INSERT AT BEGGINING-----------------------------------------------------------

void insert_begin()
{
    struct node*first= (struct node*)malloc(sizeof(struct node));
    printf("enter the data=");
    scanf("%d",&first->data);
    first->next=head;
    head=temp=first;
}

//-------------------------------------------------INSERT AT END--------------------------------------------------------------------------

void insert_end()
{
    temp=head;
    struct node*end= (struct node*)malloc(sizeof(struct node));
    printf("enter the data=");
    scanf("%d",&end->data);
    end->next=NULL;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    temp->next=end;
}

//------------------------------------------------INSERT BY POSITION--------------------------------------------------------------------------

void insert_position()
{
    int z;
    temp=head;
    struct node*middle = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&middle->data);
    printf("Enter the position to be inserted:");
    scanf("%d",&z);
    for(int i=1;i<z;i++)
    {
        temp=temp->next;
    }
    middle->next= temp->next;
    temp->next=middle;
}

//------------------------------------------------COUNT---------------------------------------------------------------

int count()
{
    temp=head;
    int z=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        z=z+1;
    }
    printf("The number of items in list is %d",z);
}

//--------------------------------------------------DELETE AT BEGGINING------------------------------------------------------

void delete_begin()
{
    temp=head;
    head=head->next;
    free(temp);
}

//-------------------------------------------------DELETE BY POSITION----------------------------------------------------------- 

void delete_position()
{
    temp=head;
    int z;
    printf("Enter position to be deleted:");
    scanf("%d",&z);
    for(int i=1;i<z-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

//------------------------------------------------DELETE AT END-----------------------------------------------------------------------

void delete_end()
{
    struct node*ptra = (struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    ptra=temp;
    temp->next=NULL;   
    free(ptra);                     
}

//------------------------------------------------SEARCH BY POSITION-------------------------------------------------------------------

int search_position()
{
    int a;
    printf("Enter the position to be searched:");
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        printf("The number found in position %d is %d",a,temp->data);
    }
    else
    {
        printf("The position was not found.");
    }
}

//-----------------------------------------------SEARCH BY VALUE-----------------------------------------------------------------------

void search_value()
{
    temp=head;
    int a,m=0;
    printf("Enter the number to be searched:");
    scanf("%d",&a);
    while(temp!=NULL)
    {
        if(temp->data ==a)
        {
            printf("The number was found.");
            m=1;
            break;
        }
        else 
        {
            m=0;
        }
        temp=temp->next;
    }
    if(m==0)
    {
        printf("The number was not found.");
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------