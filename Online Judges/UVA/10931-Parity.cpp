#include<stdio.h>
int main()
{
    unsigned long int n;
    int b[1000], count,i,j;
    scanf("%lu",&n);
    while(n!=0)
    {
        i=0;
        count=0;
        while(n>0)
        {
            b[i++] = n%2;
            n = n/2;
        }
        printf("The parity of ");
        for(i=i-1;i>=0;i--)
        {
            printf("%d",b[i]);
            if(b[i]==1)
                count++;

        }
        printf(" is %d (mod 2).\n",count);
        scanf("%lu",&n);

    }
    return 0;
}
