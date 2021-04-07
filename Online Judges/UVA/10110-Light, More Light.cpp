#include<stdio.h>
#include<math.h>
int main()
{
    long long int n, p,q,i;
    scanf("%lld",&n);
    while(n!=0)
    {
        q=0;
        p = sqrt(n);
        for(i=1;i<=p;i++)
        {
            q+=p;
        }
        if(n==q)
            printf("yes\n");
        else
            printf("no\n");
        scanf("%lld",&n);
    }

}
