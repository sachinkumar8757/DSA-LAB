#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define max 20
void push(int e);
int pop();
int top=-1,a[max];
void main()
{
    char post[max],ch;
    int i,op1,op2,result;
    printf("Enter posrfix expression\n");
    scanf("%c",post);
    for(i=0;post[i]!='\0';i++)
    {
        ch=post[i];
        if(isdigit(ch))
        push(ch-'0');
        else
        {
            op2=pop();
            op1=pop();
        switch(ch)
        {
            case '+':result=op1+op2;
            break;
             case '-':result=op1-op2;
            break;
             case '*':result=op1*op2;
            break;
             case '/':result=op1/op2;
            break;
             case '%':result=op1%op2;
            break;
             case '^':result=pow(op1,op2);
            break;
            default:printf("Invalid choice\n");
        } 
        push(result);   
        }
    }
    printf("The result is %d \n",pop());
}

void push(int e)
{
    a[++top]=e;
}

int pop()
{
    int ele;
    ele=a[top];
    top--;
    return(ele);
}