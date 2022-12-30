#include <stdio.h>
#include <stdlib.h>
void create_list();
void display();
void insert_front();
void delete_front();
void insert_last();
void delete_last();
void stack();
typedef struct node
{
    char usn[10], name[20], branch[10], sem[10], phno[10];
    struct node *link;
} node;
node *first = NULL;
int main()
{
    int ch;
    while (1)
    {
        printf("Linkedlist operation menu\n");
        printf("1:create newnode\n2:display\n3:insert front\n4:delete front\n5:insert last\n6:delete last\n7:stack\n8:exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_list();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_front();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            insert_last();
            break;
        case 6:
            delete_last();
            break;
        case 7:
            stack();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
/************************create_list******************************/
void create_list()
{
    int i = 0, n;
    printf("Enter the number of students\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Detail of student:%d\n", (i + 1));
        insert_front();
    }
}

/***********************display**********************************/
void display()
{
    if (first== NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = first;
    int total = 0;
    printf("\nUSN\tname\tbranch\tsem.\tphone no.\n");
    while (temp != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->link;
        total++;
    }
    printf("total no of list is %d\n", total);
}

/**************************insert_front*************************/

void insert_front()
{
    node *newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter usn\tname\tbranch\tsem\tphno\n");
    scanf("%s%s%s%s%s", newnode->usn, newnode->name, newnode->branch, newnode->sem, newnode->phno);
    newnode->link = first;
    first = newnode;
}

/**************************delete_front**************************/

void delete_front()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = first;
    first = first->link;
    free(temp);
}

/***************************insert_last*************************/

void insert_last()
{
    node *newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter usn\tname\tbranch\tsem\tphno\n");
    scanf("%s%s%s%s%s", newnode->usn, newnode->name, newnode->branch, newnode->sem, newnode->phno);
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        node *temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

/******************************delete_last**********************/

void delete_last()
{
    if (first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    node *slast, *temp;
    slast = temp = first;
    while (temp->link != NULL)
    {
        slast = temp;
        temp = temp->link;
    }
    slast->link = NULL;
    free(temp);
}

/*******************************stack***************************/

void stack()
{
    int ch;
    while (1)
    {
        printf("stack operation\n");
        printf("\n1:insert_front\n2:delete_front\n3:display\n4:exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert_front();
            break;
        case 2:
            delete_front();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}