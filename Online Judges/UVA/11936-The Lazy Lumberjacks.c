#include<stdio.h>
int main()
{
    int N,a,b,c;
    while(scanf("%d",&N) == 1)
    {
        while(N--)
        {
            scanf("%d %d %d",&a,&b,&c);
            if((a+b)<=c || (b+c)<=a || (c+a)<=b)
                printf("Wrong!!\n");
            else
                printf("OK\n");
        }

    }

    return 0;
}
