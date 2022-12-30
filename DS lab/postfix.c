#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define max 20
void push(int e);
int pop();
int a[max], top = -1;

void main()
{
    char post[max], ch;
    int i, op1, op2, result;
    printf("Enter the post expression\n");
    scanf("%d", post);
    for (i = 0; post[i] != '0'; i++)
    {
        ch = post[i];
        if (isdigit(ch))
            push(ch - 'o');
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = op1 , op2;
                break;
            case '%':
                result = op1 + op2;
                break;

            default:printf("Invalid character\n");
                break;
            }
            push(result);
        }
    }
    printf("result of expression is %d",pop());
}

void push(int e)
{
    top++;
    a[top]=e;
}
int pop()
{
    int ele;
    ele=a[top];
    top--;
    return(ele);
}