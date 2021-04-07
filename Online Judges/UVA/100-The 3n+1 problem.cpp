#include<stdio.h>
int main()
{
    long long int i,a,b,n,x,y,s;
    int count;
    while(scanf("%lld %lld",&x,&y)==2)
    {
        if(x<y)
        {
         a=x;
         b=y;
        }
        else
        {
            a=y;
            b=x;
        }
        s=1;
        for(i=a;i<=b;i++)
        {
            count = 1;
            for(n=i;n>1;)
            {
                if(n%2==0)
                {
                    n=n/2;
                }
                else
                {
                    n=(n+n+n)+1;
                }
                count++;
            }
            if(count>s)
            {
                s=count;
            }
        }

     printf("%lld %lld %lld\n",x,y,s);
    }
     return 0;
}
