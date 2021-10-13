#include<stdio.h>
#include<conio.h>
struct TWS //structure for tow way stack
{
    int capacity;
    int top_left,top_right;
    int *ptr;
};
struct TWS* creatTwoWayStack(int cap)
{
    struct TWS* T=(struct TWS*)malloc(sizeof(struct TWS));
    T->capacity=cap;
    T->top_left=-1;
    T->top_right=cap;
    T->ptr=(int*)malloc(sizeof(int)*cap);
    return T;
};
void push_left(struct TWS *T)
{
    if(T->top_left+1==T->top_right)
        printf("Overflow"); //overflow for left stack
    else
    {
        int data;
        printf("Enter data = ");
        scanf("%d",&data);
        T->top_left+=1;
        T->ptr[T->top_left]=data;
    }
}
void push_right(struct TWS *T)
{
    if(T->top_left+1==T->top_right)
        printf("Overflow"); // overflow for right stack
    else
    {
        int data;
        printf("Enter data = ");
        scanf("%d",&data);
        T->top_right-=1;
        T->ptr[T->top_right]=data;
    }
}
void pop_left(struct TWS *T)
{
    if(T->top_left== -1)
        printf("Underflow"); // underflow for left stack
    else
        T->top_left-=1;
}
void pop_right(struct TWS *T)
{
    if(T->top_right== T->capacity)
        printf("Underflow"); // underflow for right stack
    else
        T->top_right+=1;
}
void peek_left(struct TWS *T)
{
    if(T->top_left== -1)
        printf("No element present at the left top");
    else
        printf("Element present at left top = %d",T->ptr[T->top_left]);
}
void peek_right(struct TWS *T)
{
    if(T->top_right== T->capacity)
        printf("No element present at the right top");
    else
        printf("Element present at left top = %d",T->ptr[T->top_right]);
}
void display(struct TWS *T)
{
    if(T->top_left!=-1)
    {
        int i=0;
        while(i<=T->top_left)
        {
            printf("%d ",T->ptr[i]);
            ++i;
        }
    }
    printf("<- Top_Left Top_Right-> ");
    if(T->top_right!=T->capacity)
    {
        int i=T->top_right;
        while(i!=T->capacity)
        {
            printf("%d ",T->ptr[i]);
            ++i;
        }
    }
}
int menu()
{
    int choice;
    printf("\n\nMENU");
    printf("\n1. PUSH IN LEFT STACK");
    printf("\n2. PUSH IN RIGHT STACK");
    printf("\n3. POP FROM LEFT STACK");
    printf("\n4. POP FROM RIGHT STACK");
    printf("\n5. PEEK INTO LEFT STACK");
    printf("\n6. PEEK INTO RIGHT STACK");
    printf("\n7. EXIT");
    printf("\n\nEnter your choice = ");
    scanf("%d",&choice);
    return choice;
}
int main()
{
    struct TWS *T;
    int cap;
    printf("Enter capacity of stack = ");
    scanf("%d",&cap); 
    T = creatTwoWayStack(cap);
    while(1)
    {
        system("cls");
        display(T);
        switch(menu())
        {
        case 1:
            push_left(T);
            break;
        case 2:
            push_right(T);
            break;
        case 3:
            pop_left(T);
            break;
        case 4:
            pop_right(T);
            break;
        case 5:
            peek_left(T);
            break;
        case 6:
            peek_right(T);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Choice, Try Again!");
        }
        getch();
    }

}
