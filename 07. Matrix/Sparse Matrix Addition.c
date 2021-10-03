/* Write a Program to add Sparse Matrices*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int r,c,v;
    struct node *next;
};
void create(struct node **h)
{
    struct node *cur,*ptr;
    *h=(struct node *)malloc(sizeof(struct node));
    printf("Enter number of rows, coloumns and number of non zero elements");
    scanf("%d%d%d",&(*h)->r,&(*h)->c,&(*h)->v);
    (*h)->next=NULL;
    ptr=*h;
    for(int i=0;i<(*h)->v;i++)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        printf("Enter row, coloumn and value of non zero elements");
        scanf("%d%d%d",&cur->r,&cur->c,&cur->v);
        cur->next=NULL;
        ptr->next =cur;
        ptr=cur;
    }
}
void display1(struct node *h)
{
    struct node *ptr;
    for(ptr=h;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d\t%d\t%d",ptr->r,ptr->c,ptr->v);
        printf("\n");
    }
}
void display2(struct node *h)
{
    struct node *ptr;
    int c=0;
    for(int i=0;i<h->r;i++)
    {
        for(int j=0;j<h->c;j++)
        {
            for(ptr=h->next;ptr!=NULL;ptr=ptr->next)
            {
                if(ptr->r==i && ptr->c==j)
                {
                    printf("%d\t",ptr->v);
                    c=1;
                    break;
                }
                else
                    c=0;
            }
            if(c==0)
                printf("%d\t",0);

        }
        printf("\n");
    }
}
void add(struct node *h1,struct node *h2,struct node **h3)
{
    struct node *ptr,*cur,*p,*p2,*tmp;
    if(!(h1->r==h2->r && h1->c==h2->c))
        return;
    *h3=(struct node *)malloc(sizeof(struct node));
    (*h3)->r=h1->r;
    (*h3)->c=h1->c;
    (*h3)->v=h1->v+h2->v;
    ptr=*h3;
    for(p=h1->next;p!=NULL;p=p->next)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        cur->r=p->r;
        cur->c=p->c;
        cur->v=p->v;
        cur->next=NULL;
        ptr->next=cur;
        ptr=cur;
    }
    for(p=h2->next;p!=NULL;p=p->next)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        cur->r=p->r;
        cur->c=p->c;
        cur->v=p->v;
        cur->next=NULL;
        ptr->next=cur;
        ptr=cur;
    }
    for(p=(*h3)->next;p!=NULL;p=p->next)
    {
        tmp=p;
        p2=p->next;
        while(p2!=NULL)
        {
            if(p->r==p2->r && p->c==p2->c)
            {
                p->v=p->v+p2->v;
                tmp->next=p2->next;
                free(p2);
                p2=tmp;
            }
            tmp=p2;
            p2=p2->next;
        }
    }
}
int main()
{
    struct node *h1,*h2,*h3;
    h1=h2=h3=NULL;
    create(&h1);
    create(&h2);
    display1(h1);
    printf("1st Matrix : \n");
    display2(h1);
    printf("2nd Matrix : \n");
    display2(h2);
    add(h1,h2,&h3);
    printf("Sum of Matrix is : \n");
    display2(h3);
    return 0;
}
