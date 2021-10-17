#include<stdio.h>
const int SIZE=5;
int front=-1,rear=-1;
struct PQueue
{
    int val;
    int priority;
} pq[5],temp;

void enqueue()
{
    if(rear>=SIZE-1)
      printf("\n Queue is full\n ------------- \n");
    else
    {
        int i;
        if (front==-1)
          front=rear=0;

        else
          rear++;

        printf("\n Enter the element to be added:");
        scanf("%d",&pq[rear].val);
        printf("\n Enter its priority:");
        scanf("%d",&pq[rear].priority);
        
        if(rear>0)
        {
            temp=pq[rear];
            for(i=rear-1;i>=0;i--)
            if(temp.priority>pq[i].priority)//descending
               pq[i+1]=pq[i];
            else
              break;
            pq[i+1]=temp;

        }
        
    }
}
void dequeue()
{
    if(front==-1)
     printf("\n UnderFlow!!\n");

    else
    {
        printf("\n Element: %d with Priority: %d is deleted \n",pq[front].val,pq[front].priority);
        if(front==rear)
           front=rear=-1;
        else
         front++; 
    }
    
}

void display()
{
    if(front==-1)
      printf("\n Queue is Empty!!\n");
    else
     for(int i=front;i<=rear;i++)
       printf("\n Element:  %d \n Priority: %d \n",pq[i].val,pq[i].priority);
}
void main()
{
    int input=0;
    printf("\n Priority Queue\n --------------\n");
    while(input!=4)
    {
        printf("\n Queue Operations:\n 1.Add element(Enqueue)\n 2.Delete element(Dequeue)\n 3.Display\n 4.Quit\n");
        scanf("%d",&input);
        switch (input)
        {
         case 1: enqueue();
                 display();
                break;
         case 2: dequeue();
                 display();
                break;
         case 3: display();
                break;
         case 4: printf("\n Quitting...!");
                break;
         default: printf("\n Wrong Choice...!!\n");
                break;
        }
    }
}