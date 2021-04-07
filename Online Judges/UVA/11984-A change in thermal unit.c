#include<stdio.h>
int main()
{
    int T, C, d, i;
    float newC;
    while(scanf("%d",&T)==1)
    {
        for(i=0;i<T;i++)
        {
            scanf("%d %d",&C,&d);
            newC = (C + ((5*d)/9.0));
            printf("Case %d: %.2f\n",i+1,newC);
        }
    }

    return 0;

}
