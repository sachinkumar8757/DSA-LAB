#include<stdio.h>
#define size 5
int stack[size],top=-1;
void push();
void pop();
void display();
void palin();
int main()
{
   int ch;
   while(1)
   {
       printf("Stack Menu\n");
       printf("1:push\n2:pop\n3:display\n4:palindrome\n5:Exit\n");
       printf("\n");
       printf("Enter your choice\n");
       scanf("%d",&ch);
       switch (ch)
       {
       case 1:push();
           break;
       case 2:pop();
       break;
       case 3:display();
       break;
       case 4:palin();
       break;
       case 5:return(0);
       default:printf("invalid choice\n");
       }
   }
}
/***********************************insert element****************************************/
void push()
{
    int item;
    if (top==size-1)
    printf("stack is full\n");
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
}
/**********************************delete element****************************************/
void pop()
{
    int d;
    if(top==-1)
    printf("stack is empty\n");
    else
    {
       d=stack[top--];
       printf("deleted element is %d\n",d);
    }
}
/*********************************palindrome checking*****************************************/
void palin()
{
    int i,j=0,flag=1;
    int rev[size];
    if(top==-1)
    printf("palindrome cannot be checked\n");
    else
    {
        for(i=top;i>=0;i--,j++)
        rev[j]=stack[i];
        for(i=0;i<=top;i++)
        {
            if(rev[i]!=stack[i])
            {
                flag=0;
                break;
            }
        }
    }
if(flag)
printf("it is palindrome\n");
else
printf("it is not palindrome\n");
}
/******************************************display element************************/
void display()
{
    int i;
    if(top==-1)
    printf("stack is empty\n");
    else
    {
        printf("element of stack are:\n");
      for(i=top;i>=0;i--)
      printf("%d\t",stack[i]);
      printf("\n");
    }
}

