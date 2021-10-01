#include <stdio.h>
int push(int element, int stack[], int *top, int stackSize)
{
    if (*top == -1)
    {
        stack[stackSize - 1] = element;
        *top = stackSize - 1;
    }
    else if (*top == 0)
    {
        printf("The stack is already full. \n");
    }
    else
    {
        stack[(*top) - 1] = element;
        (*top)--;
    }
}
int pop(int stack[], int *top, int stackSize)
{
    if (*top == -1)
    {
        printf("The stack is empty. \n");
    }
    else
    {
        printf("Element popped: %d \n", stack[(*top)]);
        if ((*top) == stackSize - 1)
        {
            (*top) = -1;
        }
        else
        {
            (*top)++;
        }
    }
}
int traverse(int stack[], int*top, int stackSize){
    if (*top==-1)
    {
        printf("Stack is empty");
    }
    else{
        for (int i = *top; i >=-1; i--)
        {
            printf("%d\n",stack[i]);
        }
        
    }
    
    
}
int main()
{
    int stackSize = 4, x, n;
    int stack[stackSize];
    int top = -1;
    printf("Select 1 for push operation \nSelect 2 for pop operation \nSelect 3 for traverse operation\n");
    printf("Enter the value of n:");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter value to be pushed: ");
        scanf("%d", &x);
        push(x, stack, &top, stackSize);
        printf("Element on top: %d\n", stack[top]);
        printf("Enter value to be pushed: ");
        scanf("%d", &x);
        push(x, stack, &top, stackSize);
        printf("Element on top: %d\n", stack[top]);
        break;
    case 2:
        pop(stack, &top, stackSize);
        printf("Element on top: %c\n", stack[top]);
        pop(stack, &top, stackSize);
        printf("Top: %d\n", top);
        pop(stack, &top, stackSize);
        break;
    case 3:
        traverse(stack, &top, stackSize);
        break;

    default : break;
    }
    return 0;
}
