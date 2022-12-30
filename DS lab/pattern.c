#include<stdio.h>
int find_match(char str[100],char pat[100],char rep[100],char ans[100]);
void main()
{
    char str[100],pat[100],rep[100],ans[100];
    int flag;
    printf("Enter main string\n");
    gets(str);
    printf("Enter pattern to be searched\n");
    gets(pat);
    printf("Enter replacement string\n");
    gets(rep);
    flag=find_match(str,pat,rep,ans);
    if(flag)
    {
        printf("pattern found\n");
        printf("The string after replacement is %s",ans);
    }
    else
    printf("pattern not found\n");
}
int find_match(char str[100],char pat[100],char rep[100],char ans[100])
{
    int i,j,k,m,c,flag;
    i=j=m=c=flag=0;
    while(str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            i++;
            m++;
            if(pat[i]=='\0')
            {
            flag=1;
            printf("The pattern found at position %d",c);
            for(k=0;rep[k]!='\0';k++,j++)
            ans[j]=rep[k];
            i=0;
            c=m;
            }
        }
        else
        {
            ans[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
    ans[j]='\0';
    return flag;
}