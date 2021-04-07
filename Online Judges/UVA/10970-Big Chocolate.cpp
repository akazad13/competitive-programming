#include<stdio.h>
int main()
{
    int M, N, p,i;
    while(scanf("%d %d",&M,&N)==2)
    {
        p=0;
        for(i=1;i<=N;i++)
        {
            p+=M;
        }
        printf("%d\n",p-1);
    }
    return 0;
}
