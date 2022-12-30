#include <stdio.h>
#include <ctype.h>
void push(char x);
char pop();
int priority(char x);
char stack[100];
int top = -1;
int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression\n");
    scanf("%s", exp);
    printf("\n");
    e = exp;
    while (*e!= '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e = ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(stack[top] >= priority(*e)))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}