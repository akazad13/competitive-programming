#include<stdio.h>
int main()
{
    unsigned long long int x,p,a;

    while(scanf("%llu",&x)!=EOF)
    {
        p= x*x*(x+1)*(x+1);
        p=p/4;
        printf("%llu\n",p);
    }
    return 0;
}
