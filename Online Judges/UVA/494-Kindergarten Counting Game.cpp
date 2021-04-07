#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    freopen("D:\\494.txt","r",stdin);
    char a[1000];
    int i,count;
    while(gets(a))
    {
        count=0;
        for(i=0;a[i]!='\0';i++)
        {
            if(isalpha(a[i]) && !isalpha(a[i+1]))
                count++;
        }
    printf("%d\n",count);
    }
    return 0;
}
