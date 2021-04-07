#include<stdio.h>
int main()
{
    int T, N, i, j, a[12];
    while(scanf("%d", &T) == 1)
    {
        for(i=0; i<T; i++)
        {
            scanf("%d", &N);
            for(j=0; j<N; j++)
            {
                scanf("%d", &a[j]);
            }
            N = N/2;
            printf("Case %d: %d\n",i+1,a[N]);
        }
    }

    return 0;
}
