#include<stdio.h>
int main()
{
    int T, n, P, Q, wt[32], t, i, j, m;
    while(scanf("%d",&T) == 1)
    {
        for(i=0;i<T;i++)
        {
            t=0;
            scanf("%d %d %d",&n,&P,&Q);
            for(j=0;j<n;j++)
            {
                scanf("%d",&wt[j]);
                t= t+wt[j];
            }
            if(t<=Q)
            {
                printf("Case %d: %d\n",i+1, (n>P)?P:n);
            }
            else
            {
                m=0;
                while(j--)
                {
                    if(((t=t - wt[j]) <= Q) && (j <= P))
                    {
                        printf("Case %d: %d\n",i+1,j);
                        m=1;
                    }
                    if(m==1)
                    break;
                }
            }
        }
    }

    return 0;
}
