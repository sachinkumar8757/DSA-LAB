#include<stdio.h>
#include<stdlib.h>
#define smax 5
void push();
void pop();
void pallin();
void display();
int top=-1,stk[smax];
void main()
{
    int ch;
    while(1)
    {
        printf("Stack operation menu\n");
        printf("1:push\n2:pop\n3:display\n4:pallindrome\n5:exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:pallin();
            break;
            case 5:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}


void push()
{
    int ele;
    if(top==smax-1)
    printf("Stack is overflow\n");
    else
    {
        printf("Enter element:\n");
        scanf("%d",&ele);
        stk[++top]=ele;
    }
}

void pop()
{
    int d;
    if(top==-1)
    printf("Stack is underflow\n");
    else
    {
        d=stk[top];
        top--;
        printf("Deleled element is %d \n",d);
    }
}

void display()
{
    int i;
    if(top==-1)
    printf("Stack is empty\n");
    else
    {
        printf("Element of stack are:\n");
        for(i=top;i>=0;i--)
          printf("%d \n",stk[i]);
    }
}

void pallin()
{
    int i,j=0,flag=1;
    int rev[smax];
     if(top==-1)
     printf("Pallindrome cannot be checked\n");
     else
     {
         for(i=top;i>=0;i--,j++)
         rev[j]=stk[i];
         for(i=0;i<=top;i++)
         {
             if(rev[i]!=stk[i])
             {
                 flag=0;
                 break;
             }
         }
     }
     if(flag)
     printf("It is pallindrome\n");
     else
     printf("It is not pakkindrome\n");
}