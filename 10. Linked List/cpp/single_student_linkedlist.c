#include<stdio.h>
#include<stdlib.h>
struct data{
    int roll;
    int marks;
    char grade;
};

struct node
{
    struct data r;
    struct node *next;
};
void insert(struct node **h,int pos)
{
    struct node *current,*ptr;
    current=malloc(sizeof(struct node));
    printf("Enter roll number, marks, grade \n");
    scanf("%d",&current->r.roll);
    scanf("%d",&current->r.marks);
    scanf(" %c",&current->r.grade);
    current->next=NULL;
    if(*h==NULL)
    {
        *h=current;
    }
    else if(pos==0)
    {
        current->next=*h;
        *h=current;
    }
    else
    {
        int i=0;
        ptr=*h;
        while(i<pos-1 && ptr->next!=NULL  )
        {
            ptr=ptr->next;
            i++;
        }
        current->next=ptr->next;
        ptr->next=current;
    }
}

void delete(struct node **h, int pos)
{
    struct node *ptr, *prv;
    if(*h==NULL)
    {
        printf("List is empty \n");
    }
    else
    {
         int i=0;
        ptr=*h;
        while(i<pos-1 && ptr->next!=NULL  )
        {
            prv=ptr;
            ptr=ptr->next;
            i++;
        }
    }
    if(ptr==NULL)
    {
        printf("Data not found \n");
    }
    else if(ptr==*h)
    {
        *h=ptr->next;
        free(ptr);
    }
    else
    {
        prv->next=ptr->next;
        free(ptr);
    }

}
void update(struct node **h,int ro)
{
    struct node *ptr;
    ptr=*h;
    while(ptr!=NULL)
    {
        if(ptr->r.roll==ro)
        break;
        else
        {
            ptr=ptr->next;
        }
    }
    printf("Enter Marks and grade to be updated respectively \n");
    scanf("%d",&ptr->r.marks);
    scanf(" %c",&ptr->r.grade);
}
void display(struct node **h)
{
    struct node *ptr;
    for(ptr=*h;ptr!=NULL;ptr=ptr->next)
    {
        printf("Roll  Marks   Grade \n");
        printf("%d   %d   %c \n",ptr->r.roll,ptr->r.marks,ptr->r.grade);
    }
}
int main()
{
    int no, i;
    struct node *head=NULL;
    struct node *current,*ptr;
    printf("Enter number of students \n");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        current=malloc(sizeof(struct node));
        printf("Enter roll number, marks, grade \n");
        scanf("%d",&current->r.roll);
        scanf("%d",&current->r.marks);
        scanf(" %c",&current->r.grade);
        if(head ==NULL)
        {
            head=current;
            ptr=current;
        }
        else
        {
            ptr->next=current;
            ptr=current;
        }
    }
    display(&head);
    int a,posI,posD,rollno;
    printf("Enter 1 TO ADD A STUDENT, AT A LOCATION SPECIFIED. BY THE USER\n");
    printf("ENTER 2 TO REMOVE A STUDENT, AT A LOCATION SPECIFIED. BY THE USER\n");
    printf("ENTER 3 TO UPDATE A STUDENT RECORD, AS PER PE THE ROLL NUMBER SPECIFIED\n");
    scanf("%d",&a);

    switch (a)
    {
    case 1:
    printf("Enter your position where you want to add your new student \n");
    scanf("%d",&posI);
    insert(& head,posI);
    break;
    case 2:
    printf("Enter your position where you want to remove your new student \n");
    scanf("%d",&posD);
    delete(& head,posD);
    break;
    case 3:     printf("Enter student's roll number whose record has to be changed \n");
    scanf("%d",&rollno);
    update(&head,rollno);
    default:printf("Wrong choice! \n");
    break;
    }
    display(& head);

    return 0;
}