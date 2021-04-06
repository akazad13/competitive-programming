#include<stdio.h>
int main()
{
    short int t,n,i;

    while(scanf("%hd",&t)==1)
    {
        while(t--)
        {
            i=0;
            scanf("%hd",&n);

            if(n>10)
            {
                i=n-10;
                n=10;
            }

            printf("%d %d\n",n,i);
        }
    }
    return 0;
}
