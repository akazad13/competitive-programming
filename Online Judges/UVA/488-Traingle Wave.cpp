#include<stdio.h>
int main()
{
    int a,f,i,j,c;
    while(scanf("%d",&c)==1)
    {
        while(c--)
        {
            scanf("%d %d",&a,&f);

            while(f--)
            {
                for(i=1;i<=a;i++)
                {
                    for(j=1;j<=i;j++)
                    {
                        printf("%d",i);
                    }
                    printf("\n");
                }
                for(i=i-2;i>0;i--)
                {
                    for(j=1;j<=i;j++)
                    {
                        printf("%d",i);
                    }
                    printf("\n");
                }
                if(c>0 || f>0)
                {
                    printf("\n");
                }
            }

        }
    }
    return 0;
}
