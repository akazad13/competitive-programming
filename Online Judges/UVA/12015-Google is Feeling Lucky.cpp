#include<stdio.h>
struct WebName
{
    char name[102];
    int relevance;

};
int main()
{
    struct WebName a[10],t;
    int T,i,j,k;
    while(scanf("%d",&T)==1)
    {
        for(i=1;i<=T;i++)
        {
            for(j=0;j<10;j++)
            {
                scanf("%s %d",a[j].name,&a[j].relevance);

            }
            for(j=0;j<9;j++)
            {
                for(k=j;k<10;k++)
                {
                    if(a[j].relevance<a[k].relevance)
                    {
                        t=a[j];
                        a[j]=a[k];
                        a[k]=t;
                    }
                }
            }

            for(j=1;j<10;j++)
            {
                if(a[j-1].relevance != a[j].relevance)
                {
                    break;
                }
            }
            printf("Case #%d:\n",i);
            for(k=0;k<j;k++)
            {
                printf("%s\n",a[k].name);
            }
        }
    }

    return 0;

}
