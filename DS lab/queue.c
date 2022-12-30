#include <stdio.h>
#include <stdlib.h>
#define smax 5
void insert();
void delete ();
void display();
int rear = -1, front = 0, queue[smax];
void main()
{
    int ch;
    while (1)
    {
        printf("\nqueue operation menu\n");
        printf("1:insert\n2:delete\n3:display\n4:exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
/*******************insert element******************/
void insert()
{
    int item;
    if (rear == smax-1)
        printf("queue is full\n");
    else
    {
        printf("Enter item to be insert\n");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
    }
}
/********************delete element*****************/
void delete ()
{
    if (front>rear)
        printf("queue is empty\n");
    else
    {
        int deleted_item = queue[front];
        front++;
        printf("deleted element is %d\n", deleted_item);
    }
}
/********************display element****************/
void display()
{
    if (rear == -1)
        printf("queue is empty\n");
    else
    {
        printf("elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}