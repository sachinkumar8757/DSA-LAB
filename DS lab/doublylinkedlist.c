#include <stdio.h>
#include <stdlib.h>
void create();
void insert_front();
void delete_front();
void display();
void insert_last();
void delete_last();
typedef struct node
{
    char ssn[20], name[20], dept[20], designation[20], sal[20], phno[10];
    struct node *plink, *nlink;
} node;
node *first = NULL;

int main()
{
    int ch;
    while (1)
    {
        printf("doublylinkedlist operation menu\n");
        printf("1:create\n2:insert front\n3:delete front\n4:display\n5:insert last\n6:delete last\n7:exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            display();
            break;
        case 5:
            insert_last();
            break;
        case 6:
            delete_last();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
/**********************create******************/
void create()
{
    int n, i;

    printf("Enter no. of employee\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the detail of %d employee\n", i + 1);
        insert_last();
    }
}

/******************insert_front***************/
void insert_front()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the ssn\tname\tdept\tdesignation\tsal\tphno\n");
    scanf("%s%s%s%s%s%s", newnode->ssn, newnode->name, newnode->dept, newnode->designation, newnode->sal, newnode->phno);
    newnode->plink = NULL;
    if (first == NULL)
    {
        newnode->nlink = NULL;
        first = newnode;
        return;
    }
    first->plink = newnode;
    newnode->nlink = first;
    first = newnode;
}
/*****************delete_front**************/
void delete_front()
{
    if (first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *temp = first;
    first = first->nlink;
    free(temp);
}

/******************display********************/

void display()
{
    if (first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *temp = first;
    int total = 0;
    while (temp != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", temp->ssn, temp->name, temp->dept, temp->designation, temp->sal, temp->phno);
        temp = temp->nlink;
        total++;
    }
    printf("Total no. of node:%d\n", total);
}
/*****************insert_last*******************/
void insert_last()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the ssn\tname\tdept\tdesignation\tsal\tphno\n");
    scanf("%s%s%s%s%s%s", newnode->ssn, newnode->name, newnode->dept, newnode->designation, newnode->sal, newnode->phno);
    newnode->nlink = NULL;
    if (first == NULL)
    {
        newnode->plink = NULL;
        first = newnode;
        return;
    }
    node *temp = first;
    while (temp->nlink != NULL)
    {
        temp = temp->nlink;
    }
    temp->nlink = newnode;
    newnode->plink = temp;
}
/****************delete_last*******************/
void delete_last()
{
    if(first==NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *temp=first;
    node *newlast;
    while(temp->nlink!=NULL)
    {
        temp=temp->nlink;
    }
    newlast = temp->plink;
    newlast->nlink=NULL;
    free(temp);
}
/*void delete_last()
{
    if (first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *slast, *temp;
    slast = temp = first;
    while (temp->nlink != NULL)
    {
        slast = temp;
        temp = temp->nlink;
    }
    slast->nlink = NULL;
    free(temp);
}*/