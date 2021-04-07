#include<stdio.h>
int main()
{
    short int T,a,b,i,j;
    int sum;
    while(scanf("%hd",&T)==1)
    {
        for(i=1;i<=T;i++)
        {
            sum=0;
            scanf("%hd %hd",&a,&b);
            for(j=a;j<=b;j++)
            {
                if(j%2==1)
                    sum+=j;
            }
            printf("Case %hd: %d\n",i,sum);
        }
    }
    return 0;
}
