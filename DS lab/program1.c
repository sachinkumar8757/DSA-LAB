#include<stdio.h>
void create();
void display();
void insert_pos();
void display_pos();
int n,a[150],count;
int main()
    {
       int ch;
       while(1)
       {
           printf("1:create an array\n");
           printf("2:display an arrey\n");
           printf("3:insert an element aaat a position\n");
           printf("4:delete an element at a position\n");
           printf("5:Exit\n");
           printf("Enter your choice\n");
           scanf("%d",&ch);
           switch (ch)
           {
           case 1:if(count==0||n==0)
                create();
            else
                printf("arrey already created\n");    
               break;
           case 2:if(count==0||n<0)
                printf("arrey not created create the arrey\n");
                else
                display();    
               break;
           case 3:if(count==0||n<0)
                printf("arrey not created create arrey\n");
            else
                insert_pos();    
               break;
           case 4:if(count==0||n<0)
                printf("arrey not created create arrey\n");
            else
                delete_pos();
               break;
            case 5:return 0;
            default:printf("Invalid choice\n");
           }
       }
    }
    void create()
    {
      int i;
      printf("Enter the number of element\n");
      scanf("%d",&n);
      printf("Enter the element of arrey\n");
      for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      count++;
    }
    void display()
    {
        int i;
        printf("arrey element are\n");
        for(i=0;i<n;i++)
        printf("%d\t",a[i]);
        printf("\n");
    }
    void insert_pos()
    {
        int i,pos,item;
        printf("Enter the position and value of item to be insert in arrey\n");
        scanf("%d%d",&pos,&item);
        if(pos<=0||pos>n+1)
        printf("Not possible to insert the element\n");
        else
        {
        pos--;
        for(i=n-1;i>=pos;i--)
        {
            a[i+1]=a[i];
        }
        a[pos]=item;
        n++;
        }
    }
    void delete_pos()
    {
        int i,pos,value;
        printf("enter position of element to be deleted\n");
        scanf("%d",&pos);
        if(pos<=0||pos>n)
        printf("not possible to delete element\n");
        else
        {
        value=a[--pos];
        for(i=pos;i<n-1;i++)
         a[i]=a[i+1];
         n--;
        printf("deleted element is: %d \n",value);
        }

    }