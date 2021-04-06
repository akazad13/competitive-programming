#include<stdio.h>
int main()
{
    short int t,a,b,i;
    while(scanf("%hd",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            scanf("%hd %hd",&a,&b);
            printf("Case %hd: %hd\n",i,a+b);
        }
    }
    return 0;
}
