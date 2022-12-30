#include<stdio.h>
#include<stdlib.h>
#define smax 5
void insert();
void delete();
void display();
int rear=-1,front=0,count;
char queue[smax];
int main()
{
    int ch;
    while(1)
    {
        printf("\ncircular queue operation menu\n");
        printf("1:insert\n2:delete\n3:display\n4:exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}

void insert()
{
    char item,ch;
   if(count>=smax)
   printf("queue is overflow \n");
   else
   {
       ch=getchar();
       printf("Enter item to be inserted\n");
       scanf("%c",&item);
       rear=(rear+1)%smax;
       queue[rear]=item;
       count++;
   }
}

void delete()
{
    int d;
    if(count<=0)
    printf("queue is underflow\n");
    else
    {
        d=queue[front];
        front=(front+1)%smax;
        count--;
        printf("deleted item is %c ",d);
    }
}

void display()
{
    if(count<=0)
    printf("queue is underflow\n");
    else
    {
       int i=front;
       printf("elements of queue are:\n");
        for(int j=1;j<=count;j++)
        {
            printf("%c ",queue[i]);
            i=(i+1)%smax;
        }
    }
}