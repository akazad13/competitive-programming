#include<stdio.h>
int main()
{
    int N;
    int total;
    scanf("%d",&N);
    while(N!=0)
    {
        total=0;
        while(N>0)
        {
            total += (N*N);
            N--;
        }
        printf("%d\n",total);
        scanf("%d",&N);
    }

    return 0;
}
