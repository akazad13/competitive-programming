#include<stdio.h>
int main()
{
    int T, m1,m2,d1,d2,y1,y2,a,b,i;

    while(scanf("%d",&T)==1)
    {
        for(i=1;i<=T;i++)
        {
            scanf("%d/%d/%d",&d1,&m1,&y1);
            scanf("%d/%d/%d",&d2,&m2,&y2);

            a = y1-y2;

            if(a>0)
            {
                if(m1>m2)
                    b=a;
                else if(m1<m2)
                    b = a-1;
                else
                {
                    if(d1>=d2)
                        b = a;
                    else
                        b = a-1;
                }

                if(b>=130)
                    printf("Case #%d: Check birth date\n",i);
                else
                    printf("Case #%d: %d\n",i,b);

            }
            else if(a<0)
                printf("Case #%d: Invalid birth date\n",i);
            else
            {
                if(m1>m2)
                    printf("Case #%d: %d\n",i,a);
                else if(m1<m2)
                    printf("Case #%d: Invalid birth date\n",i);
                else
                {
                    if(d1>=d2)
                        printf("Case #%d: %d\n",i,a);
                    else
                       printf("Case #%d: Invalid birth date\n",i);
                }
            }
        }
    }

    return 0;
}
