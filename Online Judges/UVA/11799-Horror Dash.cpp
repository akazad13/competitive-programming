#include<stdio.h>
int main()
{

    short int T, N, i;
    int j, a[100], t;
    while(scanf("%hd",&T)==1)
    {
        for(i=1;i<=T;i++)
        {
            t=0;
            scanf("%hd",&N);
            for(j=0;j<N;j++)
            {
                scanf("%d",&a[j]);
            }
            for(j=0;j<N;j++)
            {
                if(a[j]>t)
                    t=a[j];
            }
            printf("Case %hd: %d\n",i,t);
        }
    }
    return 0;
}
