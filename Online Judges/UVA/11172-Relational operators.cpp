#include<stdio.h>
int main()
{
    int n;
    long long int a,b;
    while(scanf("%d",&n)==1)
    {
        while(n--)
        {
            scanf("%lld %lld",&a,&b);
            if(!(a^b))
                printf("=\n");
            else if(a>b)
                printf(">\n");
            else
                printf("<\n");
        }
    }
    return 0;
}
