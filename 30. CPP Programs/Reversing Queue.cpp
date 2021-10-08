#include <bits/stdc++.h>
# define MAX 5
using namespace std;

/* Structure with queue size and pointers */
struct queue
{
int s[MAX];
int front,rear;
}st;
stack <int> stack1;

/* Function to check if the queue is full */
int full()
{
if(st.rear >= MAX - 1)
return 1;
else
return 0;
}

/* Function to check if the queue is empty */
int empty()
{
if(st.front == -1)
return 1;
else
return 0;
}

/* Function to insert elements in a queue */
void enqueue(int num)
{
if(st.front == -1)
st.front++;
st.rear++;
st.s[st.rear] = num;
}

/* Function to delete elements from the queue */
int dequeue()
{
int x;
x = st.s[st.front];
if(st.front==st.rear)
st.front=st.rear=-1;
else
st.front++;
return x;
}

/* Function to display queue elements */
void display()
{
int i;
if(empty())
printf("\nEMPTY QUEUE\n");
else
{
printf("\nQUEUE ELEMENTS : ");
for(i = st.front ; i <= st.rear ; i++)
printf("%d ",st.s[i]);
}
printf("\n");
}

/* Function to reverse a queue using a stack */
void reverse_queue_using_stack()
{
while(!(st.front == st.rear))
{stack1.push(dequeue());}
stack1.push(dequeue());
printf("\nREVERSED QUEUE : ");
while(!stack1.empty())
{
printf("%d ",stack1.top());   // Print the top element of the stack
stack1.pop();
}
printf("\n");
exit(0);
}

/* Main function */
int main()
{
int num,choice;
st.front = st.rear = -1;
printf("\nREVERSING A QUEUE USING STACKS\n");
printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.REVERSE\n5.EXIT\n");
while(1)
{
printf("\nEnter the choice : ");
scanf("%d",&choice);
switch (choice)
{
case 1:
if(full())
{
printf("\nQUEUE IS FULL\n");
}
else
{
printf("\nEnter data : ");
scanf("%d",&num);
enqueue(num);
}
break;
case 2:
if (empty())
{
printf("\nEMPTY QUEUE\n");
}
else
printf("\nDequeued Element : %d",dequeue());
break;
case 3:
display();
break;
case 4: reverse_queue_using_stack();
break;
default: exit(0);
}}
return 0;
}
