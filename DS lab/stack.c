#include <stdio.h>
#include <stdlib.h>
#define smax 5
void push();
void pop();
void display();
int top = -1;
int stack[smax];
void main()
{
    int ch;
    while (1)
    {
        printf("stack operation menu\n");
        printf("1:push\n2:pop\n3:display\n4:exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
/**********************insert element*********************/
void push()
{
    int item;
    if (top == smax)
        printf("stack is full\n");
    else
    {
        printf("Enter number to be inserted\n");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}
/*******************delete element************************/
void pop()
{
    if (top == -1)
        printf("stack is empty\n");
    else
    {
        int ele = stack[top];
        top--;
        printf("deleted element is %d\n", ele);
    }
}
/*********************display element**********************/
void display()
{
    if (top == -1)
        printf("stack is empty\n");
    else
    {
        printf("elements are:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
