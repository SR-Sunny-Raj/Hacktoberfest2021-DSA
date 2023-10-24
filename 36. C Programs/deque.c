//5. WAP to implement stack and queue using deque.
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int data;
    struct Queue *next, *prev;
} Queue;

Queue *front = 0, *rear = 0;

void insert_start(int x)
{
    Queue *q = 0;
    q = (Queue *)malloc(sizeof(Queue));
    q->data = x;
    q->next = 0;
    q->prev = 0;

    if (front == 0)
    {
        front = q;
        rear = q;
    }

    else
    {
        q->next = front;
        front->prev = q;
        front = q;
    }
}

void insert_back(int x)
{
    Queue *q = 0;
    q = (Queue *)malloc(sizeof(Queue));
    q->data = x;
    q->next = 0;
    q->prev = 0;

    if (front == 0)
        front = q;

    else
    {
        rear->next = q;
        q->prev = rear;
    }
    rear = q;
}

void delete_start()
{
    Queue *q = front;

    front = q->next;
    q->prev = 0;
    free(q);
    q = 0;
}

void delete_back()
{
    Queue *q = rear->prev;
    free(rear);
    q->next = 0;
    rear = q;
}

void display()
{
    Queue *p = front;

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int stack()
{
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n>>");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Value=");
        int num;
        scanf("%d", &num);
        insert_start(num);
        return 1;
    case 2:
        delete_back();
        return 2;
    case 3:
        display();
        return 3;
    case 4:
        return 4;
    }
}

int queue()
{
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n>>");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Value=");
        int num;
        scanf("%d", &num);
        insert_back(num);
        return 1;
    case 2:
        delete_start();
        return 2;
    case 3:
        display();
        return 3;
    case 4:
        return 4;
    }
}

int main()
{
    printf("1. Stack\n2. Queue\n>>");
    int choice;
    scanf("%d", &choice);
    while (1)
    {
        switch (choice)
        {
        case 1:
            if(stack() == 4)
                return 0;
            break;
        case 2:
            if(queue() == 4)
                return 0;
            break;
        default:
            printf("Invalid choice");
            return 0;
        }
    }
}
