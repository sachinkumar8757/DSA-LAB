#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100
struct employee
{
    int id;
    char name[20];
};
typedef struct employee Emp;
Emp emp[max];
int a[max];
int create(int empid)
{
    int key;
    key = empid % 100;
    return key;
}

void display()
{
    int i, ch;
    printf("\n1:display all\n2:filtered display\n");
    printf("Enter your choice\n");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("The hash table is:\n");
        printf("loc\tempid\tname\n");
        for (i = 0; i < max; i++)
            printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
    }
    else
    {
        printf("The hash table is:\n");
        printf("loc\tempid\tname\n");
        for (i = 0; i < max; i++)
            if (a[i] != -1)
            {
                printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
                continue;
            }
    }
}

void linear_prob(int key, int empid)
{
    int flag = 0, count = 0, pos, i;
    if (a[key] == -1)
    {
        a[key] = key;
        printf("Enter employee name:\n");
        scanf("%s", &emp[key].name);
        emp[key].id = empid;
        return;
    }
    printf("collision occured and resolved by linear probing\n");
    for (i = key + 1; i < max; i++)
    {
        if (a[i] == -1)
        {
            pos = i;
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        for(i=0;i<key;i++)
        {
            if(a[i]==-1)
            {
                pos=i;
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    printf("Hash table overflow\n");
    else
    {
        a[pos]=pos;
        printf("Enter emp name:\n");
        scanf("%s",&emp[pos].name);
        emp[pos].id=empid;
    }
}

void main()
{
    int key,empid,i;
    int ans=1;
    printf("collision handling by linear probing\n");
    for(i=0;i<max;i++)
    {
        a[i]=-1;
    }
    do
    {
        printf("Enter 4 digit employee id:\n");
        scanf("%d",&empid);
        key=create(empid);
        linear_prob(key,empid);
        printf("Do u wish to continue(1/0\n");
        scanf("%d",&ans);
    }while(ans);
    display();
}